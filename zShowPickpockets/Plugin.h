
// This file added in headers queue
// File: "Headers.h"

namespace GOTHIC_ENGINE {
#define PLUGIN_NAME "zShowPickpockets"
	zCArray<oCInfo*> pickpocketInfos;

	int CoinWidth = 100;
	int CoinHeight = 150;

	int HotKey;
	bool_t ShowPickPockets = false;
	bool_t IconAboveHead;
	int MaxDistance;

	int GetKeyCode(zSTRING key) {
		int keyCode = Invalid;

		if (key.CompareI("KEY_ESCAPE")) { keyCode = KEY_ESCAPE; }
		if (key.CompareI("KEY_1")) { keyCode = KEY_1; }
		if (key.CompareI("KEY_2")) { keyCode = KEY_2; }
		if (key.CompareI("KEY_3")) { keyCode = KEY_3; }
		if (key.CompareI("KEY_4")) { keyCode = KEY_4; }
		if (key.CompareI("KEY_5")) { keyCode = KEY_5; }
		if (key.CompareI("KEY_6")) { keyCode = KEY_6; }
		if (key.CompareI("KEY_7")) { keyCode = KEY_7; }
		if (key.CompareI("KEY_8")) { keyCode = KEY_8; }
		if (key.CompareI("KEY_9")) { keyCode = KEY_9; }
		if (key.CompareI("KEY_0")) { keyCode = KEY_0; }
		if (key.CompareI("KEY_MINUS")) { keyCode = KEY_MINUS; }
		if (key.CompareI("KEY_EQUALS")) { keyCode = KEY_EQUALS; }
		if (key.CompareI("KEY_BACK")) { keyCode = KEY_BACK; }
		if (key.CompareI("KEY_TAB")) { keyCode = KEY_TAB; }
		if (key.CompareI("KEY_Q")) { keyCode = KEY_Q; }
		if (key.CompareI("KEY_W")) { keyCode = KEY_W; }
		if (key.CompareI("KEY_E")) { keyCode = KEY_E; }
		if (key.CompareI("KEY_R")) { keyCode = KEY_R; }
		if (key.CompareI("KEY_T")) { keyCode = KEY_T; }
		if (key.CompareI("KEY_Y")) { keyCode = KEY_Y; }
		if (key.CompareI("KEY_U")) { keyCode = KEY_U; }
		if (key.CompareI("KEY_I")) { keyCode = KEY_I; }
		if (key.CompareI("KEY_O")) { keyCode = KEY_O; }
		if (key.CompareI("KEY_P")) { keyCode = KEY_P; }
		if (key.CompareI("KEY_LBRACKET")) { keyCode = KEY_LBRACKET; }
		if (key.CompareI("KEY_RBRACKET")) { keyCode = KEY_RBRACKET; }
		if (key.CompareI("KEY_RETURN")) { keyCode = KEY_RETURN; }
		if (key.CompareI("KEY_LCONTROL")) { keyCode = KEY_LCONTROL; }
		if (key.CompareI("KEY_A")) { keyCode = KEY_A; }
		if (key.CompareI("KEY_S")) { keyCode = KEY_S; }
		if (key.CompareI("KEY_D")) { keyCode = KEY_D; }
		if (key.CompareI("KEY_F")) { keyCode = KEY_F; }
		if (key.CompareI("KEY_G")) { keyCode = KEY_G; }
		if (key.CompareI("KEY_H")) { keyCode = KEY_H; }
		if (key.CompareI("KEY_J")) { keyCode = KEY_J; }
		if (key.CompareI("KEY_K")) { keyCode = KEY_K; }
		if (key.CompareI("KEY_L")) { keyCode = KEY_L; }
		if (key.CompareI("KEY_SEMICOLON")) { keyCode = KEY_SEMICOLON; }
		if (key.CompareI("KEY_APOSTROPHE")) { keyCode = KEY_APOSTROPHE; }
		if (key.CompareI("KEY_GRAVE")) { keyCode = KEY_GRAVE; }
		if (key.CompareI("KEY_LSHIFT")) { keyCode = KEY_LSHIFT; }
		if (key.CompareI("KEY_BACKSLASH")) { keyCode = KEY_BACKSLASH; }
		if (key.CompareI("KEY_Z")) { keyCode = KEY_Z; }
		if (key.CompareI("KEY_X")) { keyCode = KEY_X; }
		if (key.CompareI("KEY_C")) { keyCode = KEY_C; }
		if (key.CompareI("KEY_V")) { keyCode = KEY_V; }
		if (key.CompareI("KEY_B")) { keyCode = KEY_B; }
		if (key.CompareI("KEY_N")) { keyCode = KEY_N; }
		if (key.CompareI("KEY_M")) { keyCode = KEY_M; }
		if (key.CompareI("KEY_COMMA")) { keyCode = KEY_COMMA; }
		if (key.CompareI("KEY_PERIOD")) { keyCode = KEY_PERIOD; }
		if (key.CompareI("KEY_SLASH")) { keyCode = KEY_SLASH; }
		if (key.CompareI("KEY_RSHIFT")) { keyCode = KEY_RSHIFT; }
		if (key.CompareI("KEY_MULTIPLY")) { keyCode = KEY_MULTIPLY; }
		if (key.CompareI("KEY_LMENU")) { keyCode = KEY_LMENU; }
		if (key.CompareI("KEY_SPACE")) { keyCode = KEY_SPACE; }
		if (key.CompareI("KEY_CAPITAL")) { keyCode = KEY_CAPITAL; }
		if (key.CompareI("KEY_F1")) { keyCode = KEY_F1; }
		if (key.CompareI("KEY_F2")) { keyCode = KEY_F2; }
		if (key.CompareI("KEY_F3")) { keyCode = KEY_F3; }
		if (key.CompareI("KEY_F4")) { keyCode = KEY_F4; }
		if (key.CompareI("KEY_F5")) { keyCode = KEY_F5; }
		if (key.CompareI("KEY_F6")) { keyCode = KEY_F6; }
		if (key.CompareI("KEY_F7")) { keyCode = KEY_F7; }
		if (key.CompareI("KEY_F8")) { keyCode = KEY_F8; }
		if (key.CompareI("KEY_F9")) { keyCode = KEY_F9; }
		if (key.CompareI("KEY_F10")) { keyCode = KEY_F10; }
		if (key.CompareI("KEY_NUMLOCK")) { keyCode = KEY_NUMLOCK; }
		if (key.CompareI("KEY_SCROLL")) { keyCode = KEY_SCROLL; }
		if (key.CompareI("KEY_NUMPAD7")) { keyCode = KEY_NUMPAD7; }
		if (key.CompareI("KEY_NUMPAD8")) { keyCode = KEY_NUMPAD8; }
		if (key.CompareI("KEY_NUMPAD9")) { keyCode = KEY_NUMPAD9; }
		if (key.CompareI("KEY_SUBTRACT")) { keyCode = KEY_SUBTRACT; }
		if (key.CompareI("KEY_NUMPAD4")) { keyCode = KEY_NUMPAD4; }
		if (key.CompareI("KEY_NUMPAD5")) { keyCode = KEY_NUMPAD5; }
		if (key.CompareI("KEY_NUMPAD6")) { keyCode = KEY_NUMPAD6; }
		if (key.CompareI("KEY_ADD")) { keyCode = KEY_ADD; }
		if (key.CompareI("KEY_NUMPAD1")) { keyCode = KEY_NUMPAD1; }
		if (key.CompareI("KEY_NUMPAD2")) { keyCode = KEY_NUMPAD2; }
		if (key.CompareI("KEY_NUMPAD3")) { keyCode = KEY_NUMPAD3; }
		if (key.CompareI("KEY_NUMPAD0")) { keyCode = KEY_NUMPAD0; }
		if (key.CompareI("KEY_DECIMAL")) { keyCode = KEY_DECIMAL; }
		if (key.CompareI("KEY_OEM_102")) { keyCode = KEY_OEM_102; }
		if (key.CompareI("KEY_F11")) { keyCode = KEY_F11; }
		if (key.CompareI("KEY_F12")) { keyCode = KEY_F12; }
		if (key.CompareI("KEY_F13")) { keyCode = KEY_F13; }
		if (key.CompareI("KEY_F14")) { keyCode = KEY_F14; }
		if (key.CompareI("KEY_F15")) { keyCode = KEY_F15; }
		if (key.CompareI("KEY_KANA")) { keyCode = KEY_KANA; }
		if (key.CompareI("KEY_ABNT_C1")) { keyCode = KEY_ABNT_C1; }
		if (key.CompareI("KEY_CONVERT")) { keyCode = KEY_CONVERT; }
		if (key.CompareI("KEY_NOCONVERT")) { keyCode = KEY_NOCONVERT; }
		if (key.CompareI("KEY_YEN")) { keyCode = KEY_YEN; }
		if (key.CompareI("KEY_ABNT_C2")) { keyCode = KEY_ABNT_C2; }
		if (key.CompareI("KEY_NUMPADEQUALS")) { keyCode = KEY_NUMPADEQUALS; }
		if (key.CompareI("KEY_PREVTRACK")) { keyCode = KEY_PREVTRACK; }
		if (key.CompareI("KEY_AT")) { keyCode = KEY_AT; }
		if (key.CompareI("KEY_COLON")) { keyCode = KEY_COLON; }
		if (key.CompareI("KEY_UNDERLINE")) { keyCode = KEY_UNDERLINE; }
		if (key.CompareI("KEY_KANJI")) { keyCode = KEY_KANJI; }
		if (key.CompareI("KEY_STOP")) { keyCode = KEY_STOP; }
		if (key.CompareI("KEY_AX")) { keyCode = KEY_AX; }
		if (key.CompareI("KEY_UNLABELED")) { keyCode = KEY_UNLABELED; }
		if (key.CompareI("KEY_NEXTTRACK")) { keyCode = KEY_NEXTTRACK; }
		if (key.CompareI("KEY_NUMPADENTER")) { keyCode = KEY_NUMPADENTER; }
		if (key.CompareI("KEY_RCONTROL")) { keyCode = KEY_RCONTROL; }
		if (key.CompareI("KEY_MUTE")) { keyCode = KEY_MUTE; }
		if (key.CompareI("KEY_CALCULATOR")) { keyCode = KEY_CALCULATOR; }
		if (key.CompareI("KEY_PLAYPAUSE")) { keyCode = KEY_PLAYPAUSE; }
		if (key.CompareI("KEY_MEDIASTOP")) { keyCode = KEY_MEDIASTOP; }
		if (key.CompareI("KEY_VOLUMEDOWN")) { keyCode = KEY_VOLUMEDOWN; }
		if (key.CompareI("KEY_VOLUMEUP")) { keyCode = KEY_VOLUMEUP; }
		if (key.CompareI("KEY_WEBHOME")) { keyCode = KEY_WEBHOME; }
		if (key.CompareI("KEY_NUMPADCOMMA")) { keyCode = KEY_NUMPADCOMMA; }
		if (key.CompareI("KEY_DIVIDE")) { keyCode = KEY_DIVIDE; }
		if (key.CompareI("KEY_SYSRQ")) { keyCode = KEY_SYSRQ; }
		if (key.CompareI("KEY_RMENU")) { keyCode = KEY_RMENU; }
		if (key.CompareI("KEY_PAUSE")) { keyCode = KEY_PAUSE; }
		if (key.CompareI("KEY_HOME")) { keyCode = KEY_HOME; }
		if (key.CompareI("KEY_UP")) { keyCode = KEY_UP; }
		if (key.CompareI("KEY_PRIOR")) { keyCode = KEY_PRIOR; }
		if (key.CompareI("KEY_LEFT")) { keyCode = KEY_LEFT; }
		if (key.CompareI("KEY_RIGHT")) { keyCode = KEY_RIGHT; }
		if (key.CompareI("KEY_END")) { keyCode = KEY_END; }
		if (key.CompareI("KEY_DOWN")) { keyCode = KEY_DOWN; }
		if (key.CompareI("KEY_NEXT")) { keyCode = KEY_NEXT; }
		if (key.CompareI("KEY_INSERT")) { keyCode = KEY_INSERT; }
		if (key.CompareI("KEY_DELETE")) { keyCode = KEY_DELETE; }
		if (key.CompareI("KEY_LWIN")) { keyCode = KEY_LWIN; }
		if (key.CompareI("KEY_RWIN")) { keyCode = KEY_RWIN; }
		if (key.CompareI("KEY_APPS")) { keyCode = KEY_APPS; }
		if (key.CompareI("KEY_POWER")) { keyCode = KEY_POWER; }
		if (key.CompareI("KEY_SLEEP")) { keyCode = KEY_SLEEP; }
		if (key.CompareI("KEY_WAKE")) { keyCode = KEY_WAKE; }
		if (key.CompareI("KEY_WEBSEARCH")) { keyCode = KEY_WEBSEARCH; }
		if (key.CompareI("KEY_WEBFAVORITES")) { keyCode = KEY_WEBFAVORITES; }
		if (key.CompareI("KEY_WEBREFRESH")) { keyCode = KEY_WEBREFRESH; }
		if (key.CompareI("KEY_WEBSTOP")) { keyCode = KEY_WEBSTOP; }
		if (key.CompareI("KEY_WEBFORWARD")) { keyCode = KEY_WEBFORWARD; }
		if (key.CompareI("KEY_WEBBACK")) { keyCode = KEY_WEBBACK; }
		if (key.CompareI("KEY_MYCOMPUTER")) { keyCode = KEY_MYCOMPUTER; }
		if (key.CompareI("KEY_MAIL")) { keyCode = KEY_MAIL; }
		if (key.CompareI("KEY_MEDIASELECT")) { keyCode = KEY_MEDIASELECT; }
		if (key.CompareI("KEY_BACKSPACE")) { keyCode = KEY_BACKSPACE; }
		if (key.CompareI("KEY_NUMPADSTAR")) { keyCode = KEY_NUMPADSTAR; }
		if (key.CompareI("KEY_LALT")) { keyCode = KEY_LALT; }
		if (key.CompareI("KEY_CAPSLOCK")) { keyCode = KEY_CAPSLOCK; }
		if (key.CompareI("KEY_NUMPADMINUS")) { keyCode = KEY_NUMPADMINUS; }
		if (key.CompareI("KEY_NUMPADPLUS")) { keyCode = KEY_NUMPADPLUS; }
		if (key.CompareI("KEY_NUMPADPERIOD")) { keyCode = KEY_NUMPADPERIOD; }
		if (key.CompareI("KEY_NUMPADSLASH")) { keyCode = KEY_NUMPADSLASH; }
		if (key.CompareI("KEY_RALT")) { keyCode = KEY_RALT; }
		if (key.CompareI("KEY_UPARROW")) { keyCode = KEY_UPARROW; }
		if (key.CompareI("KEY_PGUP")) { keyCode = KEY_PGUP; }
		if (key.CompareI("KEY_LEFTARROW")) { keyCode = KEY_LEFTARROW; }
		if (key.CompareI("KEY_RIGHTARROW")) { keyCode = KEY_RIGHTARROW; }
		if (key.CompareI("KEY_DOWNARROW")) { keyCode = KEY_DOWNARROW; }
		if (key.CompareI("KEY_PGDN")) { keyCode = KEY_PGDN; }
		if (key.CompareI("KEY_CIRCUMFLEX")) { keyCode = KEY_CIRCUMFLEX; }

		return keyCode;
	}
}