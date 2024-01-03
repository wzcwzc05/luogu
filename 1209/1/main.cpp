#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
char Mainmenu[3][20] = {"开始播放>", "设置>", "退出>"};
char Settingmenu[3][20] = {"字体颜色>",  "返回主菜单>"};
char Color[5][20] = {"蓝色", "绿色", "红色", "黄色", "白色"};
char opt;              // 获取用户输入
int flagMain = 0;      // 主菜单选项标记 0表示开始播放 1表示设置 2表示退出
int flagSetting = 0;   // 设置菜单选项标记 0表示字体颜色 1表示下落速度 2表示返回主菜单
int flagColor = 0;     // 字体颜色选项标记 0表示蓝色 1表示绿色 2表示红色 3表示黄色 4表示白色
int Interval = 200;    // 下落速度(毫秒)
void DrawSettingMenu() // 绘制设置菜单
{
    system("cls"); // 清屏
    printf("数字下落动画\n制作人:XXX\n");
    printf("TIPS:按方向键上下选择选项,按左右键调节选项,按回车键确定\n");
    for (int i = 0; i <= 1; i++)
    {
        if (flagSetting == i)
        {
            printf("%s■", Settingmenu[i]);
            if (i == 0)
                printf("  %s\n", Color[flagColor]);
        }
        else
        {
            printf("%s", Settingmenu[i]);
            if (i == 0)
                printf("  %s\n", Color[flagColor]);
        }
    }
}
void DrawMainMenu() // 绘制主菜单
{
    system("cls"); // 清屏
    printf("数字下落动画\n制作人:XXX\n");
    for (int i = 0; i <= 2; i++)
    {
        if (flagMain == i)
            printf("%s■\n", Mainmenu[i]);
        else
            printf("%s\n", Mainmenu[i]);
    }
}
void HideCursor(int x) // 隐藏光标
{
    CONSOLE_CURSOR_INFO cursor_info = {1, x};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void GotoXY(int x, int y) // 光标移动到指定位置
{
    COORD pos;
    pos.X = x - 1;
    pos.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void DrawRectangle(int x1, int y1, int x2, int y2) // 绘制边框
{
    int i;
    for (i = x1; i <= x2; i = i + 2)
    {
        GotoXY(i, y1);
        printf("■");
        GotoXY(i, y2);
        printf("■");
    }
    for (i = y1; i < y2; i = i + 1)
    {
        GotoXY(x1, i);
        printf("■");
        GotoXY(x2, i);
        printf("■");
    }
}
int main()
{
    int x1 = 10, y1 = 1, x2 = x1 + 26 + 2, y2 = y1 + 20;
    int i;
    char c;
    system("color 0f");                  // 设置控制台窗口颜色
    SetConsoleOutputCP(936);           // 设置控制台输出编码为GBK
    system("mode con cols=80 lines=22"); // 设置控制台窗口大小
    HideCursor(0);                       // 隐藏光标
    system("title 数字下落动画");        // 设置控制台窗口标题
Menu:

    DrawMainMenu(); // 绘制菜单
    do
    {
        opt = getch(); // 获取用户输入
        if (opt == 72) // 方向键上，选项上移一格
        {
            flagMain--;
            if (flagMain < 0)
                flagMain = 2;
        }
        if (opt == 80) // 方向键下，选项下移一格
        {
            flagMain++;
            if (flagMain > 2)
                flagMain = 0;
        }

        DrawMainMenu(); // 重新绘制菜单

    } while (opt != 13); // 直到用户按下回车选择选项
    if (flagMain == 2)   // 退出
    {
        system("cls");
        printf("数字下落动画\n制作人:XXX\n");
        printf("感谢使用!\n");
        system("pause");
        return 0;
    }
    if (flagMain == 1) // 设置
    {
        Settingmenu:
        system("cls");
        printf("数字下落动画\n制作人:XXX\n");
        DrawSettingMenu(); // 绘制设置菜单
        do
        {
            opt = getch(); // 获取用户输入
            if (opt == 72) // 方向键上，选项上移一格
            {
                flagSetting--;
                if (flagSetting < 0)
                    flagSetting = 2;
            }
            if (opt == 80) // 方向键下，选项下移一格
            {
                flagSetting++;
                if (flagSetting > 2)
                    flagSetting = 0;
            }
            if (opt == 75) // 方向键左，选项左移一格
            {
                if (flagSetting == 0) // 字体颜色
                {
                    flagColor--;
                    if (flagColor < 0)
                        flagColor = 4;
                }
            }
            if (opt == 77) // 方向键右，选项右移一格
            {
                if (flagSetting == 0) // 字体颜色
                {
                    flagColor++;
                    if (flagColor > 4)
                        flagColor = 0;
                }
            }
            if (opt == 13 && flagSetting == 1) // 返回主菜单
                break;
            DrawSettingMenu(); // 重新绘制菜单
        } while (true);

        // 设置字体颜色
        if (flagColor == 0) // 蓝色
            system("color 0b");
        if (flagColor == 1) // 绿色
            system("color 0a");
        if (flagColor == 2) // 红色
            system("color 0c");
        if (flagColor == 3) // 黄色
            system("color 0e");
        if (flagColor == 4) // 白色
            system("color 0f");
        goto Menu;
    }
    system("cls");                 // 清屏
    DrawRectangle(x1, y1, x2, y2); // 绘制边框
    GotoXY(x1 + 2, y2 - 1);
    printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    do
    {
        c = rand() % 26 + 'A';
        for (i = y1 + 1; i < y2 - 1; i = i + 1)
        {
            GotoXY(x1 + c - 'A' + 2, i);
            printf("%c", c);
            Sleep(Interval);
            char temp;
            if (kbhit())
            {
                temp = getch();
                if (temp == 'p' || temp=='P')   //P键 暂停动画
                {
                    MessageBox(NULL, "按下了P键,跳转设置菜单", "提示", MB_OK);
                    goto Settingmenu;
                }
                if (temp==27)   //ESC键 退出动画 返回主菜单
                {
                    MessageBox(NULL, "按下了ESC键,退出动画", "提示", MB_OK);
                    goto Menu;
                }
            }
            GotoXY(x1 + c - 'A' + 2, i);
            printf(" ");
        }
        GotoXY(x1 + c - 'A' + 2, i);
        printf("=");
        Sleep(Interval);
        GotoXY(x1 + c - 'A' + 2, i);
        printf("%c", c);
    } while (kbhit() == 0); // 按任意键退出
    system("cls");
    printf("动画播放结束!按任意键返回主菜单\n");
    system("pause");
    goto Menu;
    return 0;
}