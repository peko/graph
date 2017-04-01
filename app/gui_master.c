#include "GLFW/glfw3.h"


#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_GLFW_GL2_IMPLEMENTATION

#include "nuklear.h"
#include "nuklear_glfw_gl2.h"

#include "gui_i.h"

  ///////////////
 /// PRIVATE ///
///////////////

static GLFWwindow* win;
static struct nk_context *ctx;
static struct nk_color background;

static void 
_init(GLFWwindow* window) {
    /* GUI */
    win = window;
    ctx = nk_glfw3_init(win, NK_GLFW3_INSTALL_CALLBACKS);
    /* Load Fonts: if none of these are loaded a default font will be used  */
    /* Load Cursor: if you uncomment cursor loading please hide the cursor */
    {
        struct nk_font_atlas *atlas;
        nk_glfw3_font_stash_begin(&atlas);
        /*struct nk_font *droid = nk_font_atlas_add_from_file(atlas, "../../../extra_font/DroidSans.ttf", 14, 0);*/
        /*struct nk_font *roboto = nk_font_atlas_add_from_file(atlas, "../../../extra_font/Roboto-Regular.ttf", 14, 0);*/
        /*struct nk_font *future = nk_font_atlas_add_from_file(atlas, "../../../extra_font/kenvector_future_thin.ttf", 13, 0);*/
        /*struct nk_font *clean = nk_font_atlas_add_from_file(atlas, "../../../extra_font/ProggyClean.ttf", 12, 0);*/
        /*struct nk_font *tiny = nk_font_atlas_add_from_file(atlas, "../../../extra_font/ProggyTiny.ttf", 10, 0);*/
        /*struct nk_font *cousine = nk_font_atlas_add_from_file(atlas, "../../../extra_font/Cousine-Regular.ttf", 13, 0);*/
        nk_glfw3_font_stash_end();
        /*nk_style_load_all_cursors(ctx, atlas->cursors);*/
        /*nk_style_set_font(ctx, &droid->handle);*/
    }

    background = nk_rgb(28,48,62);
};

static void 
_update(void) {

    /* Input */
    // glfwPollEvents();
    nk_glfw3_new_frame();

    /* GUI */
    if (nk_begin(ctx, "Demo", nk_rect(50, 50, 230, 250),
        NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|
        NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE)) {
            
        enum {EASY, HARD};
        static int op = EASY;
        static int property = 20;
        nk_layout_row_static(ctx, 30, 80, 1);
        if (nk_button_label(ctx, "button"))
            fprintf(stdout, "button pressed\n");

        nk_layout_row_dynamic(ctx, 30, 2);
        if (nk_option_label(ctx, "easy", op == EASY)) op = EASY;
        if (nk_option_label(ctx, "hard", op == HARD)) op = HARD;

        nk_layout_row_dynamic(ctx, 25, 1);
        nk_property_int(ctx, "Compression:", 0, &property, 100, 10, 1);

        nk_layout_row_dynamic(ctx, 20, 1);
        nk_label(ctx, "background:", NK_TEXT_LEFT);
        nk_layout_row_dynamic(ctx, 25, 1);
        if (nk_combo_begin_color(ctx, background, nk_vec2(nk_widget_width(ctx),400))) {
            nk_layout_row_dynamic(ctx, 120, 1);
            background = nk_color_picker(ctx, background, NK_RGBA);
            nk_layout_row_dynamic(ctx, 25, 1);
            background.r = (nk_byte)nk_propertyi(ctx, "#R:", 0, background.r, 255, 1,1);
            background.g = (nk_byte)nk_propertyi(ctx, "#G:", 0, background.g, 255, 1,1);
            background.b = (nk_byte)nk_propertyi(ctx, "#B:", 0, background.b, 255, 1,1);
            background.a = (nk_byte)nk_propertyi(ctx, "#A:", 0, background.a, 255, 1,1);
            nk_combo_end(ctx);
        }
    }
    nk_end(ctx);

    /* -------------- EXAMPLES ---------------- */
    // calculator(ctx);
    // overview(ctx);
    // node_editor(ctx);
    /* ----------------------------------------- */

};

static void 
_draw(void) {
    /* Draw */
    float bg[4];
    int width, height;
    nk_color_fv(bg, background);
    glfwGetWindowSize(win, &width, &height);
    glViewport(0, 0, width, height);

    // gui drawed over scene screen already cleared
    // glClear(GL_COLOR_BUFFER_BIT);
    // glClearColor(bg[0], bg[1], bg[2], bg[3]);
    
    /* IMPORTANT: `nk_glfw_render` modifies some global OpenGL state
    * with blending, scissor, face culling and depth test and defaults everything
    * back into a default state. Make sure to either save and restore or
    * reset your own state after drawing rendering the UI. */
    nk_glfw3_render(NK_ANTI_ALIASING_ON);
    
    // glfwSwapBuffers(win);
};

static void 
_free(void) {
    nk_glfw3_shutdown();
};

  //////////////
 /// GLOBAL ///
//////////////

gui_i gui_master = {
    .init   = _init,
    .update = _update,
    .draw   = _draw,
    .free   = _free
};