#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
char Mainmenu[3][20] = {"��ʼ����>", "����>", "�˳�>"};
char Settingmenu[3][20] = {"������ɫ>",  "�������˵�>"};
char Color[5][20] = {"��ɫ", "��ɫ", "��ɫ", "��ɫ", "��ɫ"};
char opt;              // ��ȡ�û�����
int flagMain = 0;      // ���˵�ѡ���� 0��ʾ��ʼ���� 1��ʾ���� 2��ʾ�˳�
int flagSetting = 0;   // ���ò˵�ѡ���� 0��ʾ������ɫ 1��ʾ�����ٶ� 2��ʾ�������˵�
int flagColor = 0;     // ������ɫѡ���� 0��ʾ��ɫ 1��ʾ��ɫ 2��ʾ��ɫ 3��ʾ��ɫ 4��ʾ��ɫ
int Interval = 200;    // �����ٶ�(����)
void DrawSettingMenu() // �������ò˵�
{
    system("cls"); // ����
    printf("�������䶯��\n������:XXX\n");
    printf("TIPS:�����������ѡ��ѡ��,�����Ҽ�����ѡ��,���س���ȷ��\n");
    for (int i = 0; i <= 1; i++)
    {
        if (flagSetting == i)
        {
            printf("%s��", Settingmenu[i]);
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
void DrawMainMenu() // �������˵�
{
    system("cls"); // ����
    printf("�������䶯��\n������:XXX\n");
    for (int i = 0; i <= 2; i++)
    {
        if (flagMain == i)
            printf("%s��\n", Mainmenu[i]);
        else
            printf("%s\n", Mainmenu[i]);
    }
}
void HideCursor(int x) // ���ع��
{
    CONSOLE_CURSOR_INFO cursor_info = {1, x};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void GotoXY(int x, int y) // ����ƶ���ָ��λ��
{
    COORD pos;
    pos.X = x - 1;
    pos.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void DrawRectangle(int x1, int y1, int x2, int y2) // ���Ʊ߿�
{
    int i;
    for (i = x1; i <= x2; i = i + 2)
    {
        GotoXY(i, y1);
        printf("��");
        GotoXY(i, y2);
        printf("��");
    }
    for (i = y1; i < y2; i = i + 1)
    {
        GotoXY(x1, i);
        printf("��");
        GotoXY(x2, i);
        printf("��");
    }
}
int main()
{
    int x1 = 10, y1 = 1, x2 = x1 + 26 + 2, y2 = y1 + 20;
    int i;
    char c;
    system("color 0f");                  // ���ÿ���̨������ɫ
    SetConsoleOutputCP(936);           // ���ÿ���̨�������ΪGBK
    system("mode con cols=80 lines=22"); // ���ÿ���̨���ڴ�С
    HideCursor(0);                       // ���ع��
    system("title �������䶯��");        // ���ÿ���̨���ڱ���
Menu:

    DrawMainMenu(); // ���Ʋ˵�
    do
    {
        opt = getch(); // ��ȡ�û�����
        if (opt == 72) // ������ϣ�ѡ������һ��
        {
            flagMain--;
            if (flagMain < 0)
                flagMain = 2;
        }
        if (opt == 80) // ������£�ѡ������һ��
        {
            flagMain++;
            if (flagMain > 2)
                flagMain = 0;
        }

        DrawMainMenu(); // ���»��Ʋ˵�

    } while (opt != 13); // ֱ���û����»س�ѡ��ѡ��
    if (flagMain == 2)   // �˳�
    {
        system("cls");
        printf("�������䶯��\n������:XXX\n");
        printf("��лʹ��!\n");
        system("pause");
        return 0;
    }
    if (flagMain == 1) // ����
    {
        Settingmenu:
        system("cls");
        printf("�������䶯��\n������:XXX\n");
        DrawSettingMenu(); // �������ò˵�
        do
        {
            opt = getch(); // ��ȡ�û�����
            if (opt == 72) // ������ϣ�ѡ������һ��
            {
                flagSetting--;
                if (flagSetting < 0)
                    flagSetting = 2;
            }
            if (opt == 80) // ������£�ѡ������һ��
            {
                flagSetting++;
                if (flagSetting > 2)
                    flagSetting = 0;
            }
            if (opt == 75) // �������ѡ������һ��
            {
                if (flagSetting == 0) // ������ɫ
                {
                    flagColor--;
                    if (flagColor < 0)
                        flagColor = 4;
                }
            }
            if (opt == 77) // ������ң�ѡ������һ��
            {
                if (flagSetting == 0) // ������ɫ
                {
                    flagColor++;
                    if (flagColor > 4)
                        flagColor = 0;
                }
            }
            if (opt == 13 && flagSetting == 1) // �������˵�
                break;
            DrawSettingMenu(); // ���»��Ʋ˵�
        } while (true);

        // ����������ɫ
        if (flagColor == 0) // ��ɫ
            system("color 0b");
        if (flagColor == 1) // ��ɫ
            system("color 0a");
        if (flagColor == 2) // ��ɫ
            system("color 0c");
        if (flagColor == 3) // ��ɫ
            system("color 0e");
        if (flagColor == 4) // ��ɫ
            system("color 0f");
        goto Menu;
    }
    system("cls");                 // ����
    DrawRectangle(x1, y1, x2, y2); // ���Ʊ߿�
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
                if (temp == 'p' || temp=='P')   //P�� ��ͣ����
                {
                    MessageBox(NULL, "������P��,��ת���ò˵�", "��ʾ", MB_OK);
                    goto Settingmenu;
                }
                if (temp==27)   //ESC�� �˳����� �������˵�
                {
                    MessageBox(NULL, "������ESC��,�˳�����", "��ʾ", MB_OK);
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
    } while (kbhit() == 0); // ��������˳�
    system("cls");
    printf("�������Ž���!��������������˵�\n");
    system("pause");
    goto Menu;
    return 0;
}