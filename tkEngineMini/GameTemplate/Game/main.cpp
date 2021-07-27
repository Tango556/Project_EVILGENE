#include "stdafx.h"
#include "system/system.h"


///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数。
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//ゲームの初期化。
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));

	//////////////////////////////////////
	// ここから初期化を行うコードを記述する。
	//////////////////////////////////////

	//ゲームオブジェクトマネージャーのインスタンスを作成する。
	GameObjectManager::CreateInstance();
	PhysicsWorld::CreateInstance();
	
	/*struct DirectionLight
	{
		Vector3 ligDirection;
		float pad;
		Vector3 ligColor;
	};*/

	DirectionLight dirLig;
	//ライトは斜め上から当たっている。
	dirLig.ligDirection.x = 1.0f;
	dirLig.ligDirection.y = -1.0f;
	dirLig.ligDirection.z = -1.0f;
	//正規化する
	dirLig.ligDirection.Normalize();
	//ライトのカラーは灰色
	dirLig.SetColor({ 1.0f,1.0f,1.0f });

	dirLig.eyePos = g_camera3D->GetPosition();

	//////////////////////////////////////
	// 初期化を行うコードを書くのはここまで！！！
	//////////////////////////////////////
	auto& renderContext = g_graphicsEngine->GetRenderContext();

	Model Uni;
	Model BackGround;

	ModelInitData uni;
	uni.m_tkmFilePath = "Assets/modelData/unityChan.tkm";
	uni.m_fxFilePath = "Assets/shader/model.fx";

	uni.m_expandConstantBuffer = &dirLig;
	uni.m_expandConstantBufferSize = sizeof(dirLig);

	ModelInitData BG;
	BG.m_tkmFilePath = "Assets/modelData/bg/bg.tkm";
	BG.m_fxFilePath = "Assets/shader/model.fx";

	BG.m_expandConstantBuffer = &dirLig;
	BG.m_expandConstantBufferSize = sizeof(dirLig);

	Uni.Init(uni);
	BackGround.Init(BG);

	// ここからゲームループ。
	while (DispatchWindowMessage())
	{
		//レンダリング開始。
		g_engine->BeginFrame();
		

		//////////////////////////////////////
		//ここから絵を描くコードを記述する。
		//////////////////////////////////////
		
		GameObjectManager::GetInstance()->ExecuteUpdate();
		GameObjectManager::GetInstance()->ExecuteRender(renderContext);
		
		Uni.Draw(renderContext);
		BackGround.Draw(renderContext);
		//////////////////////////////////////
		//絵を描くコードを書くのはここまで！！！
		//////////////////////////////////////
		g_engine->EndFrame();
	}
	//ゲームオブジェクトマネージャーを削除。
	GameObjectManager::DeleteInstance();
	return 0;
}

