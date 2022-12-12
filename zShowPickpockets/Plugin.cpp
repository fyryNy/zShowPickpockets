// This file added in headers queue
// File: "Sources.h"
#include "resource.h"

namespace GOTHIC_ENGINE {
	void ShowCoin(zCView* view, const zVEC3& worldPos, int transparency) {
		if (!view)
			return;

		zCCamera* cam = ogame->GetCamera();
		if (!cam)
			return;

		zVEC3 pos = cam->GetTransform(zCAM_TRAFO_VIEW) * worldPos;
		if (pos[2] < cam->nearClipZ)
			return;

		int x, y;
		cam->Project(&pos, x, y);
		x = view->anx(x);
		y = view->any(y);

		x = x - CoinWidth / 2;

		if (x < 0 || x > 8192 || y < 0 || y > 8192)
			return;

		zCOLOR color = zCOLOR(255, 200, 0);

		zCView* Coin = new zCView();
		Coin->InsertBack("ICON_COINS.TGA");
		view->InsertItem(Coin);
		Coin->SetPos(x, y);
		Coin->SetSize(CoinWidth, CoinHeight);
		Coin->SetColor(color);
		Coin->SetTransparency(transparency);
		Coin->SetAlphaBlendFunc(zRND_ALPHA_FUNC_BLEND);
		Coin->Blit();
		view->RemoveItem(Coin);
	}

	void GetPickPockets() {
		auto list = ogame->GetInfoManager()->infoList.next;
		while (list) {
			auto info = list->data;
			list = list->next;

			if (!info->name.HasWordI("pickpocket"))
				continue;

			int idx = parser->GetIndex(info->name + "_DOIT");
			if (idx == Invalid)
				continue;

			if (!pickpocketInfos.IsInList(info))
				pickpocketInfos.Insert(info);
		}
	}

	bool_t CanPickPocket(oCNpc* npc) {
		if (npc->attribute[NPC_ATR_HITPOINTS] <= 0)
			return false;

		for (int i = 0; i < pickpocketInfos.GetNumInList(); i++) {
			auto info = pickpocketInfos[i];

			if (info->GetNpcID() != npc->GetInstance())
				continue;

			parser->SetInstance("SELF", npc);
			parser->SetInstance("OTHER", player);

			return info->InfoConditions();
		}

		return false;
	}

	void ShowPickPockets_Loop() {
		if (!ShowPickPockets)
			return;

		zCView* screenMain = zNEW(zCView)(0, 0, 8192, 8192);
		screen->InsertItem(screenMain);

		auto list = ogame->GetWorld()->CastTo<oCWorld>()->voblist_npcs->next;

		while (list) {
			oCNpc* npc = list->data;
			list = list->next;
			if (!npc)
				continue;

			if (!npc->GetAIState())
				continue;

			if (static_cast<int>(player->GetDistanceToVob(*npc)) > MaxDistance)
				continue;

			if (!CanPickPocket(npc))
				continue;

			zVEC3 npcPos = npc->GetPositionWorld();

			if (IconAboveHead)
				npcPos[1] += 125.0f;

			int transparency = 255;
			if (!player->CanSee(npc, 1))
				transparency = 80;

			ShowCoin(screenMain, npcPos, transparency);
		}

		screenMain->Blit();
		screen->RemoveItem(screenMain);
	}

	void Game_Entry() {
	}

	void Game_Init() {
		MaxDistance = zoptions->ReadInt(PLUGIN_NAME, "MaxDistance", 3000);
		IconAboveHead = zoptions->ReadBool(PLUGIN_NAME, "IconAboveHead", true);
		HotKey = GetKeyCode(zoptions->ReadString(PLUGIN_NAME, "HotKey", "KEY_LBRACKET"));
	}

	void Game_Exit() {
	}

	void Game_PreLoop() {
	}

	void Game_Loop() {
		if (!ogame || !player)
			return;

		if (ogame->singleStep || ogame->pause_screen || player->attribute[NPC_ATR_HITPOINTS] <= 0 || zcon->IsVisible() || player->inventory2.IsOpen())
			return;

		if (HotKey != Invalid && zKeyToggled(HotKey))
			ShowPickPockets = !ShowPickPockets;

		ShowPickPockets_Loop();
	}

	void Game_PostLoop() {
	}

	void Game_MenuLoop() {
	}

	// Information about current saving or loading world
	TSaveLoadGameInfo& SaveLoadGameInfo = UnionCore::SaveLoadGameInfo;

	void Game_SaveBegin() {
	}

	void Game_SaveEnd() {
	}

	void LoadBegin() {
		pickpocketInfos.EmptyList();
	}

	void LoadEnd() {
		GetPickPockets();
	}

	void Game_LoadBegin_NewGame() {
		LoadBegin();
	}

	void Game_LoadEnd_NewGame() {
		LoadEnd();
	}

	void Game_LoadBegin_SaveGame() {
		LoadBegin();
	}

	void Game_LoadEnd_SaveGame() {
		LoadEnd();
	}

	void Game_LoadBegin_ChangeLevel() {
		LoadBegin();
	}

	void Game_LoadEnd_ChangeLevel() {
		LoadEnd();
	}

	void Game_LoadBegin_Trigger() {
	}

	void Game_LoadEnd_Trigger() {
	}

	void Game_Pause() {
	}

	void Game_Unpause() {
	}

	void Game_DefineExternals() {
	}

	void Game_ApplyOptions() {
	}

	/*
	Functions call order on Game initialization:
	  - Game_Entry           * Gothic entry point
	  - Game_DefineExternals * Define external script functions
	  - Game_Init            * After DAT files init

	Functions call order on Change level:
	  - Game_LoadBegin_Trigger     * Entry in trigger
	  - Game_LoadEnd_Trigger       *
	  - Game_Loop                  * Frame call window
	  - Game_LoadBegin_ChangeLevel * Load begin
	  - Game_SaveBegin             * Save previous level information
	  - Game_SaveEnd               *
	  - Game_LoadEnd_ChangeLevel   *

	Functions call order on Save game:
	  - Game_Pause     * Open menu
	  - Game_Unpause   * Click on save
	  - Game_Loop      * Frame call window
	  - Game_SaveBegin * Save begin
	  - Game_SaveEnd   *

	Functions call order on Load game:
	  - Game_Pause              * Open menu
	  - Game_Unpause            * Click on load
	  - Game_LoadBegin_SaveGame * Load begin
	  - Game_LoadEnd_SaveGame   *
	*/

#define AppDefault True
	CApplication* lpApplication = !CHECK_THIS_ENGINE ? Null : CApplication::CreateRefApplication(
		Enabled(AppDefault) Game_Entry,
		Enabled(AppDefault) Game_Init,
		Enabled(AppDefault) Game_Exit,
		Enabled(AppDefault) Game_PreLoop,
		Enabled(AppDefault) Game_Loop,
		Enabled(AppDefault) Game_PostLoop,
		Enabled(AppDefault) Game_MenuLoop,
		Enabled(AppDefault) Game_SaveBegin,
		Enabled(AppDefault) Game_SaveEnd,
		Enabled(AppDefault) Game_LoadBegin_NewGame,
		Enabled(AppDefault) Game_LoadEnd_NewGame,
		Enabled(AppDefault) Game_LoadBegin_SaveGame,
		Enabled(AppDefault) Game_LoadEnd_SaveGame,
		Enabled(AppDefault) Game_LoadBegin_ChangeLevel,
		Enabled(AppDefault) Game_LoadEnd_ChangeLevel,
		Enabled(AppDefault) Game_LoadBegin_Trigger,
		Enabled(AppDefault) Game_LoadEnd_Trigger,
		Enabled(AppDefault) Game_Pause,
		Enabled(AppDefault) Game_Unpause,
		Enabled(AppDefault) Game_DefineExternals,
		Enabled(AppDefault) Game_ApplyOptions
	);
}