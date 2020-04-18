/*****************************************************************************\
 * 文件：Easy2D.h
 * 作者：张银峰
 *
 * 描述：Easy2D 是一个简易的2D图形库，
 *      用于协助我们在学习C/C++期间，建立有趣的图形化小游戏项目。
 *
 * 版本：1.7
 * 版权：Copyright (C) 2013-2048 GLimix Studio (ZYF)
\*****************************************************************************/
#ifndef EASY2D_H
#define EASY2D_H

#define EASY2D_MAJOR_VERSION    1
#define EASY2D_MINOR_VERSION    7

//=============================================================================
// 导入符号定义
//=============================================================================
#ifndef E2DAPI
    #if defined(WIN32) || defined(_WINDOW)
        #ifdef __cplusplus
            #define E2DAPI extern "C" __declspec(dllimport)
        #else
            #define E2DAPI __declspec(dllimport)
        #endif
    #else
        #define E2DAPI extern "C"
    #endif
#endif

#ifndef EASY2D_EXPORTS
#pragma comment(lib, "Easy2D.lib")
#endif

//=============================================================================
// 类型与声明
//=============================================================================
typedef struct E2DPoint
{
    int x;
    int y;
} E2DPoint;

typedef struct E2DRect
{
    int x, y;
    int w, h;
} E2DRect;

typedef struct E2DColor
{
    unsigned char r, g, b, a;
} E2DColor;

typedef enum E2DRendererFlip
{
    E2D_FLIP_NONE       = 0,
    E2D_FLIP_HORIZONTAL = 1,
    E2D_FLIP_VERTICAL   = 2
} E2DRendererFlip;

typedef enum E2DBlendMode
{
    E2D_BLENDMODE_NONE    = 0,
    E2D_BLENDMODE_BLEND   = 1,
    E2D_BLENDMODE_ADD     = 2,
    E2D_BLENDMODE_MOD     = 4,
    E2D_BLENDMODE_INVALID = -1
} E2DBlendMode;

typedef enum E2DFontStyle
{
    E2D_FONT_NORMAL        = 0,
    E2D_FONT_BOLD          = 1,
    E2D_FONT_ITALIC        = 2,
    E2D_FONT_UNDERLINE     = 4,
    E2D_FONT_STRIKETHROUGH = 8
} E2DFontStyle;

typedef enum E2DTextAlign
{
    E2D_ALIGN_LEFT    = 0x01,
    E2D_ALIGN_RIGHT   = 0x02,
    E2D_ALIGN_HCENTER = 0x04,
    E2D_ALIGN_TOP     = 0x20,
    E2D_ALIGN_BOTTOM  = 0x40,
    E2D_ALIGN_VCENTER = 0x80,
    E2D_ALIGN_CENTER  = E2D_ALIGN_HCENTER | E2D_ALIGN_VCENTER
} E2DTextAlign;

typedef enum E2DAudioType
{
    E2D_MUSIC = 1,
    E2D_SOUND = 2
} E2DAudioType;

typedef enum E2DKeyboardEvent
{
    E2D_KEYDOWN,
    E2D_KEYUP
} E2DKeyboardEvent;

typedef enum E2DMouseEvent
{
    E2D_MOUSEBUTTONDOWN,
    E2D_MOUSEBUTTONUP,
    E2D_MOUSEMOVE
} E2DMouseEvent;

typedef enum E2DMouseButton
{
    E2D_MB_LEFT,
    E2D_MB_RIGHT,
    E2D_MB_MIDDLE,
} E2DMouseButton;

typedef enum E2DScancode
{
    E2D_SCANCODE_UNKNOWN = 0,

    E2D_SCANCODE_A = 4,
    E2D_SCANCODE_B = 5,
    E2D_SCANCODE_C = 6,
    E2D_SCANCODE_D = 7,
    E2D_SCANCODE_E = 8,
    E2D_SCANCODE_F = 9,
    E2D_SCANCODE_G = 10,
    E2D_SCANCODE_H = 11,
    E2D_SCANCODE_I = 12,
    E2D_SCANCODE_J = 13,
    E2D_SCANCODE_K = 14,
    E2D_SCANCODE_L = 15,
    E2D_SCANCODE_M = 16,
    E2D_SCANCODE_N = 17,
    E2D_SCANCODE_O = 18,
    E2D_SCANCODE_P = 19,
    E2D_SCANCODE_Q = 20,
    E2D_SCANCODE_R = 21,
    E2D_SCANCODE_S = 22,
    E2D_SCANCODE_T = 23,
    E2D_SCANCODE_U = 24,
    E2D_SCANCODE_V = 25,
    E2D_SCANCODE_W = 26,
    E2D_SCANCODE_X = 27,
    E2D_SCANCODE_Y = 28,
    E2D_SCANCODE_Z = 29,

    E2D_SCANCODE_1 = 30,
    E2D_SCANCODE_2 = 31,
    E2D_SCANCODE_3 = 32,
    E2D_SCANCODE_4 = 33,
    E2D_SCANCODE_5 = 34,
    E2D_SCANCODE_6 = 35,
    E2D_SCANCODE_7 = 36,
    E2D_SCANCODE_8 = 37,
    E2D_SCANCODE_9 = 38,
    E2D_SCANCODE_0 = 39,

    E2D_SCANCODE_RETURN = 40,
    E2D_SCANCODE_ESCAPE = 41,
    E2D_SCANCODE_BACKSPACE = 42,
    E2D_SCANCODE_TAB = 43,
    E2D_SCANCODE_SPACE = 44,

    E2D_SCANCODE_F1 = 58,
    E2D_SCANCODE_F2 = 59,
    E2D_SCANCODE_F3 = 60,
    E2D_SCANCODE_F4 = 61,
    E2D_SCANCODE_F5 = 62,
    E2D_SCANCODE_F6 = 63,
    E2D_SCANCODE_F7 = 64,
    E2D_SCANCODE_F8 = 65,
    E2D_SCANCODE_F9 = 66,
    E2D_SCANCODE_F10 = 67,
    E2D_SCANCODE_F11 = 68,
    E2D_SCANCODE_F12 = 69,

    E2D_SCANCODE_PRINTSCREEN = 70,
    E2D_SCANCODE_SCROLLLOCK = 71,
    E2D_SCANCODE_PAUSE = 72,
    E2D_SCANCODE_INSERT = 73,

    E2D_SCANCODE_HOME = 74,
    E2D_SCANCODE_PAGEUP = 75,
    E2D_SCANCODE_DELETE = 76,
    E2D_SCANCODE_END = 77,
    E2D_SCANCODE_PAGEDOWN = 78,
    E2D_SCANCODE_RIGHT = 79,
    E2D_SCANCODE_LEFT = 80,
    E2D_SCANCODE_DOWN = 81,
    E2D_SCANCODE_UP = 82,
} E2DScancode;

//=============================================================================
// 客户端回调函数原型
//=============================================================================
typedef void (*E2DRenderCallback)();
typedef void (*E2DUpdateCallback)(float elapsed);
typedef void (*E2DKeyboardCallback)(E2DKeyboardEvent kbe, E2DScancode sc);
typedef void (*E2DMouseCallback)(E2DMouseEvent me, int x, int y, int state[3]);

//=============================================================================
// 引擎接口
//=============================================================================
E2DAPI int  E2D_Init(const char *title, int width, int height);
E2DAPI void E2D_Run();
E2DAPI void E2D_Release();
E2DAPI void E2D_SetClearColor(E2DColor color);
E2DAPI void E2D_RenderFunc(E2DRenderCallback render);
E2DAPI void E2D_UpdateFunc(E2DUpdateCallback update);
E2DAPI void E2D_KeyboardFunc(E2DKeyboardCallback keyboard);
E2DAPI void E2D_MouseFunc(E2DMouseCallback mouse);

E2DAPI void E2D_SetRenderDrawColor(E2DColor color);
E2DAPI void E2D_DrawPoint(int x, int y);
E2DAPI void E2D_DrawPoints(const E2DPoint *points, int count);
E2DAPI void E2D_DrawLine(int x1, int y1, int x2, int y2);
E2DAPI void E2D_DrawLines(const E2DPoint *points, int count);
E2DAPI void E2D_DrawRect(const E2DRect *rect);
E2DAPI void E2D_FillRect(const E2DRect *rect);

E2DAPI int  E2D_CreateTexture(const char *filename);
E2DAPI void E2D_DestroyTexture(int id);
E2DAPI void E2D_GetTextureSize(int id, int *w, int *h);
E2DAPI void E2D_SetTextureBlend(int id, E2DColor color, E2DBlendMode mode);
E2DAPI void E2D_ResetTextureBlend(int id);
E2DAPI void E2D_RenderTexture(int id, int x, int y, E2DRendererFlip flip);
E2DAPI void E2D_RenderTextureEx(int id, int sx, int sy, int w, int h, int dx, int dy, E2DRendererFlip flip);
E2DAPI void E2D_RenderTextureEx2(int id, const E2DRect *src, const E2DRect *dst, E2DRendererFlip flip);
E2DAPI void E2D_RenderTextureEx3(int id, int x, int y, double angle, const E2DPoint *center, E2DRendererFlip flip);
E2DAPI void E2D_RenderTextureEx4(int id, int sx, int sy, int w, int h, int dx, int dy, double angle, const E2DPoint *center, E2DRendererFlip flip);
E2DAPI void E2D_RenderTextureEx5(int id, const E2DRect *src, const E2DRect *dst, double angle, const E2DPoint *center, E2DRendererFlip flip);

E2DAPI int  E2D_LoadFont(const char *filename, int ptsize);
E2DAPI void E2D_UnloadFont(int id);
E2DAPI void E2D_TextOut(int id, const char *text, int x, int y, E2DColor color, int *cid);
E2DAPI void E2D_DrawText(int id, const char *text, E2DRect rect, int align, E2DColor color, int *cid);
E2DAPI void E2D_DeleteText(int cid);

E2DAPI int  E2D_LoadAudio(const char *filename, E2DAudioType type);
E2DAPI void E2D_UnloadAudio(int id);
E2DAPI void E2D_PlayAudio(int id, int loops, int fadein);
E2DAPI void E2D_StopAudio(int types, int fadeout);
E2DAPI void E2D_PauseAudio(int types);
E2DAPI void E2D_ResumeAudio(int types);

#endif