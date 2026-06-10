#include <SDL3/SDL.h>
#ifdef USE_SDL_TTF
#include <SDL3_ttf/SDL_ttf.h>
#endif
#include "stack/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_W 700
#define WINDOW_H 600
#define BOX_W 140
#define BOX_H 44
#define BOX_GAP 6
#define STACK_CENTER_X 150
#define STACK_BASE_Y 520
#define STACK_TOP_Y 80
#define MAX_VISIBLE 10

#define BTN_PUSH_X 400
#define BTN_POP_X 400
#define BTN_CLR_X 400
#define BTN_W 140
#define BTN_H 44
#define BTN_GAP 14
#define BTN_Y_START 80

#ifdef USE_SDL_TTF
static TTF_Font *font = NULL;
#endif

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    StackInt *stack;
    int running;
    char status_msg[64];
    int status_timer;
} App;

static SDL_Color color_bg = {30, 30, 40, 255};
static SDL_Color color_box = {60, 100, 180, 255};
static SDL_Color color_top = {200, 80, 60, 255};
static SDL_Color color_btn = {70, 70, 90, 255};
static SDL_Color color_btn_hover = {100, 100, 130, 255};
static SDL_Color color_text = {220, 220, 230, 255};
static SDL_Color color_label = {180, 180, 200, 255};

static int init_app(App *app)
{
    app->window = NULL;
    app->renderer = NULL;
    app->stack = create_stack_int();
    app->running = 1;
    app->status_msg[0] = '\0';
    app->status_timer = 0;

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
        return 0;
    }

#ifdef USE_SDL_TTF
    if (!TTF_Init())
    {
        fprintf(stderr, "TTF_Init: %s\n", SDL_GetError());
    }
#endif

    if (!SDL_CreateWindowAndRenderer("Stack Visualization", WINDOW_W, WINDOW_H, 0, &app->window, &app->renderer))
    {
        fprintf(stderr, "SDL_CreateWindowAndRenderer: %s\n", SDL_GetError());
        return 0;
    }

#ifdef USE_SDL_TTF
    font = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 20);
    if (!font)
    {
        font = TTF_OpenFont("C:/Windows/Fonts/msyh.ttc", 20);
    }
    if (!font)
    {
        font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 20);
    }
    if (!font)
    {
        fprintf(stderr, "TTF_OpenFont: %s\n", SDL_GetError());
    }
#endif

    srand((unsigned)time(NULL));
    return 1;
}

static void close_app(App *app)
{
#ifdef USE_SDL_TTF
    if (font)
    {
        TTF_CloseFont(font);
    }
    TTF_Quit();
#endif
    if (app->stack)
    {
        free_stack(app->stack);
    }
    if (app->renderer)
    {
        SDL_DestroyRenderer(app->renderer);
    }
    if (app->window)
    {
        SDL_DestroyWindow(app->window);
    }
    SDL_Quit();
}

static int is_hover(int mx, int my, int rx, int ry, int rw, int rh)
{
    return mx >= rx && mx < rx + rw && my >= ry && my < ry + rh;
}

#ifdef USE_SDL_TTF
static void render_text(SDL_Renderer *renderer, const char *text, int x, int y, SDL_Color color)
{
    if (!font)
    {
        return;
    }
    SDL_Surface *surf = TTF_RenderText_Blended(font, text, SDL_strlen(text), color);
    if (!surf)
    {
        return;
    }
    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surf);
    if (tex)
    {
        SDL_FRect dst = {(float)x, (float)y, (float)surf->w, (float)surf->h};
        SDL_RenderTexture(renderer, tex, NULL, &dst);
        SDL_DestroyTexture(tex);
    }
    SDL_DestroySurface(surf);
}
#else
static void render_text(SDL_Renderer *renderer, const char *text, int x, int y, SDL_Color color)
{
    (void)renderer;
    (void)text;
    (void)x;
    (void)y;
    (void)color;
}
#endif

static void draw_button(SDL_Renderer *renderer, const char *label, int x, int y, int w, int h, int hover)
{
    SDL_FRect rect = {(float)x, (float)y, (float)w, (float)h};
    SDL_SetRenderDrawColor(renderer, hover ? color_btn_hover.r : color_btn.r,
                           hover ? color_btn_hover.g : color_btn.g,
                           hover ? color_btn_hover.b : color_btn.b, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, color_label.r, color_label.g, color_label.b, 255);
    SDL_RenderRect(renderer, &rect);
    render_text(renderer, label, x + 8, y + 10, color_text);
}

static void draw_number_box(SDL_Renderer *renderer, int value, int x, int y, int is_top)
{
    SDL_FRect rect = {(float)x, (float)y, BOX_W, BOX_H};
    if (is_top)
    {
        SDL_SetRenderDrawColor(renderer, color_top.r, color_top.g, color_top.b, 255);
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, color_box.r, color_box.g, color_box.b, 255);
    }
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, color_label.r, color_label.g, color_label.b, 255);
    SDL_RenderRect(renderer, &rect);

    char buf[16];
    snprintf(buf, sizeof(buf), "%d", value);
    render_text(renderer, buf, x + BOX_W / 2 - 12, y + 10, color_text);
}

static void render(App *app)
{
    SDL_SetRenderDrawColor(app->renderer, color_bg.r, color_bg.g, color_bg.b, 255);
    SDL_RenderClear(app->renderer);

    /* Collect stack elements by traversing */
    int values[MAX_VISIBLE];
    int count = 0;

    StackIntNode *cur = app->stack->top;
    while (cur && count < MAX_VISIBLE)
    {
        values[count++] = cur->data;
        cur = cur->next;
    }
    if (strcmp(app->status_msg, "Cleared") == 0)
    {
        SDL_Log("%d", __LINE__);
    }
    /* Draw stack elements from bottom to top */
    for (int i = 0; i < count; i++)
    {
        int idx = count - 1 - i; /* bottom of visual = last in array */
        int vy = STACK_BASE_Y - (i + 1) * (BOX_H + BOX_GAP);
        if (vy < STACK_TOP_Y)
        {
            break;
        }
        draw_number_box(app->renderer, values[idx],
                        STACK_CENTER_X - BOX_W / 2, vy,
                        i == 0);
    }

    /* Draw "TOP" label if stack not empty */
    if (count > 0)
    {
        int vy = STACK_BASE_Y - 1 * (BOX_H + BOX_GAP);
        render_text(app->renderer, "TOP", STACK_CENTER_X + BOX_W / 2 + 10, vy + 10, color_top);
    }

    /* Draw title */
    render_text(app->renderer, "Stack Visualization", 20, 20, color_text);

    /* Draw buttons */
    float fmx, fmy;
    Uint32 buttons = SDL_GetMouseState(&fmx, &fmy);
    int mx = (int)fmx, my = (int)fmy;
    (void)buttons;

    draw_button(app->renderer, "Push", BTN_PUSH_X, BTN_Y_START, BTN_W, BTN_H,
                is_hover(mx, my, BTN_PUSH_X, BTN_Y_START, BTN_W, BTN_H));
    draw_button(app->renderer, "Pop", BTN_POP_X, BTN_Y_START + BTN_H + BTN_GAP, BTN_W, BTN_H,
                is_hover(mx, my, BTN_POP_X, BTN_Y_START + BTN_H + BTN_GAP, BTN_W, BTN_H));
    draw_button(app->renderer, "Clear", BTN_CLR_X, BTN_Y_START + 2 * (BTN_H + BTN_GAP), BTN_W, BTN_H,
                is_hover(mx, my, BTN_CLR_X, BTN_Y_START + 2 * (BTN_H + BTN_GAP), BTN_W, BTN_H));

    /* Info panel */
    char buf[64];
    snprintf(buf, sizeof(buf), "Size: %d", app->stack->size);
    render_text(app->renderer, buf, BTN_PUSH_X, BTN_Y_START + 3 * (BTN_H + BTN_GAP) + 20, color_text);

    if (app->stack->size > 0)
    {
        int top_val;
        top(app->stack, &top_val);
        snprintf(buf, sizeof(buf), "Top: %d", top_val);
        render_text(app->renderer, buf, BTN_PUSH_X, BTN_Y_START + 4 * (BTN_H + BTN_GAP) + 20, color_text);
    }

    if (app->status_timer > 0)
    {
        render_text(app->renderer, app->status_msg, BTN_PUSH_X, BTN_Y_START + 5 * (BTN_H + BTN_GAP) + 20, color_label);
        app->status_timer--;
    }

    SDL_RenderPresent(app->renderer);
}

static void set_status(App *app, const char *msg)
{
    snprintf(app->status_msg, sizeof(app->status_msg), "%s", msg);
    app->status_timer = 120;
}

static void handle_click(App *app, int mx, int my)
{
    if (is_hover(mx, my, BTN_PUSH_X, BTN_Y_START, BTN_W, BTN_H))
    {
        int val = rand() % 100;
        push(app->stack, val);
        char buf[32];
        snprintf(buf, sizeof(buf), "Pushed %d", val);
        set_status(app, buf);
    }
    else if (is_hover(mx, my, BTN_POP_X, BTN_Y_START + BTN_H + BTN_GAP, BTN_W, BTN_H))
    {
        if (app->stack->size == 0)
        {
            set_status(app, "Stack is empty!");
        }
        else
        {
            int val;
            pop(app->stack, &val);
            char buf[32];
            snprintf(buf, sizeof(buf), "Popped %d", val);
            set_status(app, buf);
        }
    }
    else if (is_hover(mx, my, BTN_CLR_X, BTN_Y_START + 2 * (BTN_H + BTN_GAP), BTN_W, BTN_H))
    {
        clear_stack(app->stack);
        set_status(app, "Cleared");
    }
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    App app;
    if (!init_app(&app))
    {
        return 1;
    }

    while (app.running)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_EVENT_QUIT)
            {
                app.running = 0;
            }
            else if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
            {
                handle_click(&app, (int)e.button.x, (int)e.button.y);
            }
            else if (e.type == SDL_EVENT_KEY_DOWN)
            {
                if (e.key.key == SDLK_ESCAPE)
                {
                    app.running = 0;
                }
            }
        }
        render(&app);
        SDL_Delay(16);
    }

    close_app(&app);
    return 0;
}
