#include "stdafx.h"
#include "system/system.h"


///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));

	//////////////////////////////////////
	// �������珉�������s���R�[�h���L�q����B
	//////////////////////////////////////

	//�Q�[���I�u�W�F�N�g�}�l�[�W���[�̃C���X�^���X���쐬����B
	GameObjectManager::CreateInstance();
	PhysicsWorld::CreateInstance();
	
	/*struct DirectionLight
	{
		Vector3 ligDirection;
		float pad;
		Vector3 ligColor;
	};*/

	DirectionLight dirLig;
	//���C�g�͎΂ߏォ�瓖�����Ă���B
	dirLig.ligDirection.x = 1.0f;
	dirLig.ligDirection.y = -1.0f;
	dirLig.ligDirection.z = -1.0f;
	//���K������
	dirLig.ligDirection.Normalize();
	//���C�g�̃J���[�͊D�F
	dirLig.SetColor({ 1.0f,1.0f,1.0f });

	dirLig.eyePos = g_camera3D->GetPosition();

	//////////////////////////////////////
	// ���������s���R�[�h�������̂͂����܂ŁI�I�I
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

	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		//�����_�����O�J�n�B
		g_engine->BeginFrame();
		

		//////////////////////////////////////
		//��������G��`���R�[�h���L�q����B
		//////////////////////////////////////
		
		GameObjectManager::GetInstance()->ExecuteUpdate();
		GameObjectManager::GetInstance()->ExecuteRender(renderContext);
		
		Uni.Draw(renderContext);
		BackGround.Draw(renderContext);
		//////////////////////////////////////
		//�G��`���R�[�h�������̂͂����܂ŁI�I�I
		//////////////////////////////////////
		g_engine->EndFrame();
	}
	//�Q�[���I�u�W�F�N�g�}�l�[�W���[���폜�B
	GameObjectManager::DeleteInstance();
	return 0;
}

