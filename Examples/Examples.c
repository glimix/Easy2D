#include <stdio.h>
#include <string.h>
#include "Easy2D.h"

char title[128];
int recipe = 0;

void getRecipe()
{
    printf("Recipe names:\n");
    printf("[1] start      : create Easy2D framework\n");
    printf("[2] primitives : draw primitives\n");
    printf("[3] texture    : use texture\n");
    printf("[4] blend      : texture & blend\n");
    printf("[5] animation  : frame animations\n");
    printf("[6] text       : render text\n");
    printf("[7] audio      : play music & sound\n");
    printf("[8] keyboard   : keyboard test\n");
    printf("[9] mouse      : mouse test\n");

    printf("\nrecipe: ");
    int r = scanf_s("%d", &recipe);
    if (r != 1) recipe = 1;
    else if (recipe < 1 || recipe > 9) recipe = 1;

    const char *titles[] = {
        "start",
        "primitives",
        "texture",
        "blend",
        "animation",
        "text",
        "audio",
        "keboard",
        "mouse"
    };

    strcpy_s(title, 128, titles[recipe - 1]);
}

//=============================================================================
void recipe1_render()
{
    static int counter = 0;
    counter++;

    if (counter == 20)
    {
        E2DColor blue = { 0, 0, 255, 255 };
        E2D_SetClearColor(blue);
    }
    else if (counter == 40)
    {
        E2DColor green = { 0, 255, 0, 255 };
        E2D_SetClearColor(green);
    }
    else if (counter == 60)
    {
        E2DColor black = { 0, 0, 0, 255 };
        E2D_SetClearColor(black);
        counter = 0;
    }
}

//=============================================================================
void recipe2_render()
{
    E2DColor red = { 255, 0, 0, 255 };
    E2D_SetRenderDrawColor(red);
    E2D_DrawPoint(10, 10);

    E2DColor yellow = { 255, 255, 0, 255 };
    E2D_SetRenderDrawColor(yellow);
    E2D_DrawLine(50, 50, 100, 300);

    E2DColor green = { 0, 255, 0, 255 };
    E2D_SetRenderDrawColor(green);
    E2DRect rect = { 200, 200, 50, 50 };
    E2D_DrawRect(&rect);

    E2DRect rect2 = { 400, 400, 150, 50 };
    E2D_FillRect(&rect2);
}

//=============================================================================
int g_r3tex;

void recipe3_load()
{
    g_r3tex = E2D_CreateTexture("./media/enemy.png");
}

void recipe3_unload()
{
    E2D_DestroyTexture(g_r3tex);
}

void recipe3_render()
{
    if (g_r3tex > 0)
    {
        E2D_RenderTexture(g_r3tex, 20, 20, E2D_FLIP_NONE);
        E2D_RenderTexture(g_r3tex, 20, 80, E2D_FLIP_HORIZONTAL);
        E2D_RenderTexture(g_r3tex, 20, 140, E2D_FLIP_VERTICAL); // ����ͼ��ĶԳ��ԣ��㿴������תЧ����
        E2D_RenderTextureEx3(g_r3tex, 20, 200, 45.0, 0x0, E2D_FLIP_NONE);

        int w, h;
        E2D_GetTextureSize(g_r3tex, &w, &h);
        E2DRect src = { 0, 0, w, h };
        E2DRect dst = { 20, 260, 100, 100 };
        E2D_RenderTextureEx2(g_r3tex, &src, &dst, E2D_FLIP_NONE);
    }
}

//=============================================================================
int g_r4tex;

void recipe4_load()
{
    g_r4tex = E2D_CreateTexture("./media/box.png");
}

void recipe4_unload()
{
    E2D_DestroyTexture(g_r4tex);
}

void recipe4_render()
{
    // ԭͼ
    E2D_RenderTexture(g_r4tex, 20, 20, E2D_FLIP_NONE);

    // ��ɫ
    E2DColor red = { 255, 0, 0, 255 };
    E2D_SetTextureBlend(g_r4tex, red, E2D_BLENDMODE_BLEND);
    E2D_RenderTexture(g_r4tex, 20, 100, E2D_FLIP_NONE);

    // ͸��
    red.a = 64;
    E2D_SetTextureBlend(g_r4tex, red, E2D_BLENDMODE_BLEND);
    E2D_RenderTexture(g_r4tex, 20, 180, E2D_FLIP_NONE);

    // �رջ�ɫ������״̬���ƻᵼ�µ�һ�����ӱ���ɫ��
    E2D_ResetTextureBlend(g_r4tex);
}

//=============================================================================
int g_r5tex;

void recipe5_load()
{
    g_r5tex = E2D_CreateTexture("./media/explosion.png");
}

void recipe5_unload()
{
    E2D_DestroyTexture(g_r5tex);
}

void recipe5_render()
{
    // ԭͼ
    E2D_RenderTexture(g_r5tex, 20, 20, E2D_FLIP_NONE);

    static int i = 0;
    static int count = 0;

    // ÿ֡ͼ���СΪ64x64������8֡��
    // ÿ��Ⱦ7�λ�����һ֡
    if (count++ == 7)
    {
        i++;
        count = 0;
        if (i == 8)
            i = 0;
    }

    int x = i * 64;
    E2D_RenderTextureEx(g_r5tex, x, 0, 64, 64, 250, 250, E2D_FLIP_NONE);
}

//=============================================================================
int g_r6font;
int g_r6text1 = 0;
int g_r6text2 = 0;

void recipe6_load()
{
    g_r6font = E2D_LoadFont("C:\\Windows\\Fonts\\msyh.ttc", 17);
}

void recipe6_unload()
{
    E2D_UnloadFont(g_r6font);
    E2D_DeleteText(g_r6text1);
    E2D_DeleteText(g_r6text2);
}

void recipe6_render()
{
    // ֱ�����
    E2DColor color = { 255, 0, 0, 255 };
    E2D_TextOut(g_r6font, "Hello Easy2D!", 20, 20, color, 0);

    // ���������Ч�ʸߣ�
    color.r = 0; color.g = 255;
    E2D_TextOut(g_r6font, "��ã����磡", 20, 40, color, &g_r6text1);

    // ��ʽ�����
    color.g = 0; color.b = 255;
    E2DRect rect = { 50, 100, 700, 400 };
    E2D_SetRenderDrawColor(color);
    E2D_DrawRect(&rect);

    color.r = 138; color.g = 24; color.b = 192;
    E2D_DrawText(g_r6font, "Easy2D V1.7 for Windows", rect, E2D_ALIGN_LEFT, color, 0);
    E2D_DrawText(g_r6font, "Easy2D - �����õ�2Dͼ�ο�", rect, E2D_ALIGN_CENTER, color, 0);
    E2D_DrawText(g_r6font, "���ߣ������� (glimx.com)", rect, E2D_ALIGN_RIGHT | E2D_ALIGN_BOTTOM, color, &g_r6text2);
}

//=============================================================================
int g_r7music;
int g_r7sound;

void recipe7_load()
{
    g_r7music = E2D_LoadAudio("./media/announce.ogg", E2D_MUSIC);
    g_r7sound = E2D_LoadAudio("./media/shoot.wav", E2D_SOUND);
}

void recipe7_unload()
{
    E2D_UnloadAudio(g_r7music);
    E2D_UnloadAudio(g_r7sound);
}

void recipe7_render()
{
    static int counter = 0;
    counter++;

    // �㲻Ӧ�ý����������Ĵ����д�ڳ�����Ⱦ�����С�
    // ����Ҫ�ڴ���ĳ���¼������л������������ӵ�ʱ���������ļ���

    if (counter == 20)
    {
        // ����һ�Σ��޵��룩
        E2D_PlayAudio(g_r7music, 1, 0);
    }
    else if (counter == 140)
    {
        // ֹͣ�������֣�2�뵭��Ч����
        E2D_StopAudio(E2D_MUSIC, 2000);
        // ����5��
        E2D_PlayAudio(g_r7sound, 5, 0);
    }
    else if (counter == 350)
    {
        // ѭ�����ţ���3�뵭��Ч��
        E2D_PlayAudio(g_r7music, -1, 3000);
    }
    else if (counter == 550)
    {
        E2D_PauseAudio(E2D_MUSIC | E2D_SOUND);
    }
    else if (counter == 750)
    {
        E2D_ResumeAudio(E2D_MUSIC | E2D_SOUND);
    }
}

//=============================================================================
int g_r8tex;
int g_r8x = 400;
int g_r8y = 300;
int g_r8font;
int g_r8text;

void keyboard(E2DKeyboardEvent kbe, E2DScancode sc)
{
    if (kbe == E2D_KEYDOWN)
    {
        int vec = 10;
        if (sc == E2D_SCANCODE_LEFT) g_r8x -= vec;
        else if (sc == E2D_SCANCODE_RIGHT) g_r8x += vec;
        else if (sc == E2D_SCANCODE_UP) g_r8y -= vec;
        else if (sc == E2D_SCANCODE_DOWN) g_r8y += vec;
    }
}

void recipe8_load()
{
    // ��Ҫ����װ������Ӧ����
    E2D_KeyboardFunc(keyboard);
    g_r8tex = E2D_CreateTexture("./media/box.png");
    g_r8font = E2D_LoadFont("C:\\Windows\\Fonts\\msyh.ttc", 17);
}

void recipe8_unload()
{
    E2D_DeleteText(g_r8tex);
    E2D_UnloadFont(g_r8font);
    E2D_DestroyTexture(g_r8tex);
}

void recipe8_render()
{
    E2DColor color = { 192, 192, 192, 255 };
    E2D_TextOut(g_r8font, "use the (UP/DOWN/LEFT/RIGHT) keys to move it!", 10, 10, color, &g_r8text);
    E2D_RenderTexture(g_r8tex, g_r8x, g_r8y, E2D_FLIP_NONE);
}

//=============================================================================
int g_r9tex;
int g_r9x = 400;
int g_r9y = 300;
int g_r9font;
int g_r9text;

void mouse(E2DMouseEvent me, int x, int y, int state[3])
{
    static int pressed = 0;

    if (me == E2D_MOUSEBUTTONDOWN)
    {
        pressed = 1;
    }
    else if (me == E2D_MOUSEBUTTONUP)
    {
        g_r9x = x;
        g_r9y = y;

        printf("mouse up: (%d:%d) (%d-%d-%d)\n",
            x, y, state[0], state[1], state[2]);

        pressed = 0;
    }
    else if (me == E2D_MOUSEMOVE)
    {
        if (pressed)
        {
            g_r9x = x;
            g_r9y = y;
        }
    }
}

void recipe9_load()
{
    // ��Ҫ����װ�����Ӧ����
    E2D_MouseFunc(mouse);
    g_r9tex = E2D_CreateTexture("./media/box.png");
    g_r9font = E2D_LoadFont("C:\\Windows\\Fonts\\msyh.ttc", 17);
}

void recipe9_unload()
{
    E2D_DeleteText(g_r9tex);
    E2D_UnloadFont(g_r9font);
    E2D_DestroyTexture(g_r9tex);
}

void recipe9_render()
{
    E2DColor color = { 192, 192, 192, 255 };
    E2D_TextOut(g_r9font, "click mouse (left/middle/right) button", 10, 10, color, &g_r8text);
    E2D_RenderTexture(g_r9tex, g_r9x, g_r9y, E2D_FLIP_NONE);
}

//=============================================================================
void render()
{
    static void(*rfuncs[])() =
    {
        recipe1_render, recipe2_render, recipe3_render,
        recipe4_render, recipe5_render, recipe6_render,
        recipe7_render, recipe8_render, recipe9_render
    };

    rfuncs[recipe - 1]();
}

//=============================================================================
int main()
{
    getRecipe();

    // Easy2D���ʼ��
    if (!E2D_Init(title, 800, 600))
        return -1;

    // ʾ����Դ����
         if (recipe == 3) recipe3_load();
    else if (recipe == 4) recipe4_load();
    else if (recipe == 5) recipe5_load();
    else if (recipe == 6) recipe6_load();
    else if (recipe == 7) recipe7_load();
    else if (recipe == 8) recipe8_load();
    else if (recipe == 9) recipe9_load();

    // ������Ⱦ�ص�����
    E2D_RenderFunc(render);

    // �ÿ����������
    E2D_Run();

    // ��Դж��
         if (recipe == 3) recipe3_unload();
    else if (recipe == 4) recipe4_unload();
    else if (recipe == 5) recipe5_unload();
    else if (recipe == 6) recipe6_unload();
    else if (recipe == 7) recipe7_unload();
    else if (recipe == 8) recipe8_unload();
    else if (recipe == 9) recipe9_unload();

    // Easy2Dж��
    E2D_Release();

    return 0;
}