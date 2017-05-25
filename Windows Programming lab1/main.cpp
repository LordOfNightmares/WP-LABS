#include <windows.h>
#define BUTTON_1 102
#define BUTTON_2 103
#define TEXT_1 104


/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    RECT rect;
    static HWND button1, button2, textfield;
    static int cxCoord, cyCoord;
    LRESULT textSize;
    COLORREF TextColor = RGB(100, 100, 100);
    HBRUSH brush1 = CreateSolidBrush(RGB(176, 23, 31));
    HBRUSH brush2 = CreateSolidBrush(RGB(0, 23, 31));
    HFONT hFont,hFont2;
    hFont = CreateFont(0,0,0,0,
                               FW_DONTCARE,
                               FALSE,FALSE,
                               FALSE,
                               DEFAULT_CHARSET,
                               OUT_OUTLINE_PRECIS,
                               CLIP_DEFAULT_PRECIS,
                               DEFAULT_QUALITY,
                               VARIABLE_PITCH,
                               TEXT("Impact"));
    hFont2= CreateFont(0,0,0,0,FW_DONTCARE,
                               FALSE,FALSE,
                               FALSE,
                               DEFAULT_CHARSET,
                               OUT_OUTLINE_PRECIS,
                               CLIP_DEFAULT_PRECIS,
                               DEFAULT_QUALITY,
                               VARIABLE_PITCH,
                               TEXT("Default"));
    switch (Message)
    {
    case WM_CREATE:
    {

        textfield = CreateWindowEx(NULL,
                                   TEXT("STATIC"),
                                   TEXT("Random text output."),
                                   WS_VISIBLE|WS_CHILD,
                                   0,0,0,0,
                                    hwnd,
                                   (HMENU)TEXT_1,
                                   GetModuleHandle(NULL),
                                   NULL);
        button1 = CreateWindowEx(NULL,
                                 TEXT("BUTTON"),
                                 TEXT("The 1st button"),
                                 WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 0, 0,0, 0,
                                 hwnd,
                                 (HMENU)BUTTON_1,
                                 GetModuleHandle(NULL),
                                 NULL);
        button2 = CreateWindowEx(NULL,
                                 TEXT("BUTTON"),
                                 TEXT("The 2nd button"),
                                 WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON|BS_OWNERDRAW,
                                 0, 0, 0, 0,
                                 hwnd,
                                 (HMENU)BUTTON_2,
                                 GetModuleHandle(NULL),
                                 NULL);

        break;

    }
    case WM_DRAWITEM:
		LPDRAWITEMSTRUCT Item;
		Item = (LPDRAWITEMSTRUCT)lParam;
		FillRect(Item->hDC, &Item->rcItem, CreateSolidBrush(RGB(100, 100,100)));
		SelectObject(Item->hDC, CreateSolidBrush(0));
		if (Item->itemState & ODS_SELECTED)
		{
			SetTextColor(Item->hDC, RGB(0, 255, 0));
			SelectObject(Item->hDC, CreateSolidBrush(RGB(0,4,23)));
			SelectObject(Item->hDC, CreatePen(PS_SOLID, 2, RGB(100, 100, 255)));
		}
		else
		{
			SetTextColor(Item->hDC, RGB(255, 0, 0));
			SelectObject(Item->hDC, CreateSolidBrush(RGB(5, 5, 255)));
			SelectObject(Item->hDC, CreatePen(PS_SOLID, 2, RGB(0, 255, 1)));

		}

		SetBkMode(Item->hDC, TRANSPARENT);
		RoundRect(Item->hDC, Item->rcItem.left, Item->rcItem.top, Item->rcItem.right, Item->rcItem.bottom, 0, 0);
		int len;
		len = GetWindowTextLength(Item->hwndItem);
		LPSTR lpBuff;
		lpBuff = new char[len + 1];
		GetWindowTextA(Item->hwndItem, lpBuff, len + 1);
		DrawTextA(Item->hDC, lpBuff, len, &Item->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
		return 0;
    case WM_SIZE:
        cxCoord = LOWORD(lParam); // 544
        cyCoord = HIWORD(lParam); // 375
        MoveWindow(button1,
                   cxCoord-150, cyCoord/3-80, 110, 40,
                   TRUE);
        MoveWindow(button2,
                   cxCoord-150, cyCoord/3-20, 110, 40,
                   TRUE);
        MoveWindow(textfield,
                   cxCoord/2-60, cyCoord/3-70, 200, 20,
                   TRUE);
        break;
    case WM_COMMAND:
        switch (wParam)
        {
        case BUTTON_1:

            SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (ULONG)brush1);
            RedrawWindow(hwnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_FRAME);
            SendMessage (textfield, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage (button2, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage (button1, WM_SETFONT, (WPARAM)hFont2, TRUE);
            break;
        case BUTTON_2:
            SetClassLongPtr(hwnd,GCLP_HBRBACKGROUND, (ULONG)brush2);
            RedrawWindow(hwnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_FRAME);
            SendMessage (textfield, WM_SETFONT, (WPARAM)hFont2, TRUE);
             SendMessage (button1, WM_SETFONT, (WPARAM)hFont, TRUE);
             SendMessage (button2, WM_SETFONT, (WPARAM)hFont2, TRUE);
            break;
        }
        return 0;
        /* Upon destruction, tell the main thread to stop */
        case WM_DESTROY:
        {
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        }

        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, Message, wParam, lParam);
        }
        return 0;
    }

    /* The 'main' function of Win32 GUI programs: this is where execution starts */
    int WINAPI WinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPSTR lpCmdLine,
                       int nCmdShow)
    {
        WNDCLASSEX wc; /* A properties struct of our window */
        HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
        MSG msg; /* A temporary location for all messages */


        /* The Window structure */
        memset(&wc, 0, sizeof(wc));
        wc.cbSize = sizeof(WNDCLASSEX);
        wc.lpszClassName = "WindowClass";
        wc.lpfnWndProc = WndProc; /* This is where we will send messages to */
        wc.style = CS_HREDRAW | CS_VREDRAW;/* Catch double-clicks */
        wc.hIconSm=0;

        wc.hInstance = hInstance;
        /* Use default icon and mouse-pointer */
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
        wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */
        wc.cbClsExtra=0;
        wc.cbWndExtra=0;
        // Windows's default color as the background
        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + WHITE_BRUSH);


        if (!RegisterClassEx(&wc))
        {
            MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
            return 0;
        }

        hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,
                              "WindowClass",
                              "The most basic window!",
                              WS_VISIBLE | WS_OVERLAPPEDWINDOW,
                              300, //CW_USEDEFAULT, /* x position*/
                              150,//CW_USEDEFAULT, /* y position*/
                              640, /* width */
                              480, /* height */
                              NULL, NULL, hInstance, NULL);

        if (hwnd == NULL)
        {
            MessageBox(NULL, "Window Creation Failed!", "Error!",
                       MB_ICONEXCLAMATION | MB_OK);
            return 0;
        }
        int result = MessageBox(0,"Yes or no choose","That box ",
                                MB_YESNO);
        switch (result)
        {
        /*Window will close if you press yes*/
        case IDYES:
            MessageBox(0,"You just pressed yes, the window will close","yes!",0);
            return msg.wParam;
            break;
        /*Window will remain if you press no
        example of custom message box.*/
        case IDNO:
            MessageBox(0,"You just pressed no","No!",0);
            MessageBox(0,"Custom Message_box","Custom No!",
                       MB_ICONEXCLAMATION);
            break;
        }
        /*
        This is the heart of our program where all input is processed and
        sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
        this loop will not produce unreasonably high CPU usage
        */
        while (GetMessage(&msg, NULL, 0, 0) > 0)
        {
            /* If no error is received... */
            TranslateMessage(&msg); /* Translate key codes to chars if present */
            DispatchMessage(&msg); /* Send it to WndProc */
        }
        return msg.wParam;
    }
