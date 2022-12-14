/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonAPI.h"
#include "LessonX.h"

#include <math.h>
////////////////////////////////////////////////////////////////////////////////
//
//
int			g_iGameState		=	0;		// ��Ϸ״̬��0 -- ��Ϸ�����ȴ���ʼ״̬��1 -- ���¿ո����ʼ����ʼ����Ϸ��2 -- ��Ϸ������

float		g_fSpeedLeft		=	0.f;  	// �����ٶ�
float		g_fSpeedRight	=	0.f;  	// ��
float		g_fSpeedTop		    =	0.f;  	// ��
float		g_fSpeedBottom	    =	0.f;  	// ��
//��ȡ����߽��ȫ�ֱ���
float       g_fScreenLeft  ;
float       g_fScreenRight   ;
float       g_fScreenTop       ;
float       g_fScreenBottom    ;

float        fPosX;
float        fPosY;

int         circle=0;
int         n=0;
int         flag=0;
//������Ϸ������־��ȫ�ֱ���
int         game_flag_2;

//����ʱ������
float         time_left=60;
//
void		GameInit();
void		GameRun( float fDeltaTime );
void		GameEnd();
void        TimeLimit( float fDeltaTime );
//==============================================================================
//
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�


//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬.
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void GameMainLoop( float	fDeltaTime )
{
    switch( g_iGameState )
    {
    // ��ʼ����Ϸ�������һ���������
    case 1:
    {
        GameInit();
        g_iGameState	=	2; // ��ʼ��֮�󣬽���Ϸ״̬����Ϊ������
    }
    break;

    // ��Ϸ�����У����������Ϸ�߼�
    case 2:
    {
        // TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
        if( game_flag_2 == 0 )
        {
            TimeLimit( fDeltaTime );
            GameRun( fDeltaTime );
        }
        else
        {
            // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
            g_iGameState	=	0;
            GameEnd();
        }
    }
    break;

    // ��Ϸ����/�ȴ����ո����ʼ
    case 0:
    default:
        break;
    };
}

//==============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������

void    TimeLimit( float fDeltaTime )
{

    time_left -= fDeltaTime;
    dSetTextValue( "time_left", time_left );

    if(n >= 5 && flag==1 )
    {
        game_flag_2   =   1;
    }
    else if(time_left <= 0 && ( n<5 || flag==0 ))
    {
        game_flag_2   =   2;
    }

}

void GameInit()
{
    game_flag_2 = 0;

    g_fScreenLeft       =   dGetScreenLeft();
    g_fScreenRight      =   dGetScreenRight();
    g_fScreenTop        =   dGetScreenTop();
    g_fScreenBottom     =   dGetScreenBottom();
    dSetSpriteWorldLimit("man", WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop, g_fScreenRight, g_fScreenBottom);

    dPlaySound("Lifting.ogg",1,1);
    dSetSpriteVisible("jieshao",1);

    dSetSpriteCollisionActive( "man",1, 1 );
    dSetSpriteCollisionPhysicsReceive( "wall_1", 1 );
    dSetSpriteCollisionPhysicsReceive( "wall_2", 1 );
    dSetSpriteCollisionPhysicsReceive( "wall_3", 1 );
    dSetSpriteCollisionPhysicsReceive( "wall_4", 1 );
    dSetSpriteCollisionPhysicsReceive( "wall_5", 1 );

    fPosX = dGetSpritePositionX( "logo" );
    fPosY = dGetSpritePositionY( "logo" );
}
//==============================================================================
//
// ÿ����Ϸ������
void GameRun( float fDeltaTime )
{

}
//==============================================================================
//
// ������Ϸ����
void GameEnd()
{
    dStopAllSound();
    if(game_flag_2 == 1)
    {
        dLoadMap( "third.t2d" );
        dPlaySound("Lifting.ogg", 1, 1 );
    }

    if(game_flag_2 == 2)
    {
        dLoadMap( "game_over_2.t2d" );
        dPlaySound("gameover.ogg", 1, 1 );
    }
}
//==========================================================================
//
// ����ƶ�
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseMove( const float fMouseX, const float fMouseY )
{

}
//==========================================================================
//
// �����
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
//==========================================================================
//
// ��굯��
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
//==========================================================================
//
// ���̰���
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
void OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{
    if(iKey==KEY_SPACE)
        circle++;
    if(circle==1)
        g_iGameState=1;
    if(circle==2)
        dDeleteSprite("jieshao");
    if(g_iGameState	== 2)
    {
        {
            switch(iKey)
            {
            case KEY_W:
                g_fSpeedTop = -10.f;
                break;
            case KEY_A:
                g_fSpeedLeft = -15.f;
                break;
            case KEY_S:
                g_fSpeedBottom = 10.f;
                break;
            case KEY_D:
                g_fSpeedRight = 15.f;
                break;
            default:
                break;
            }
            dSetSpriteLinearVelocity("man", g_fSpeedLeft + g_fSpeedRight, g_fSpeedTop + g_fSpeedBottom);
            if((g_fSpeedLeft + g_fSpeedRight) > 0.f)
                dSetSpriteFlipX("man", 0);
            else if((g_fSpeedLeft + g_fSpeedRight) < 0.f)
                dSetSpriteFlipX("man", 1);
        }
    }

}
//==========================================================================
//
// ���̵���
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
void OnKeyUp( const int iKey )
{
    if(g_iGameState	==	2)
    {
        {
            switch(iKey)
            {
            case KEY_W:
                g_fSpeedTop = 0.f;
                break;
            case KEY_A:
                g_fSpeedLeft = 0.f;
                break;
            case KEY_S:
                g_fSpeedBottom = 0.f;
                break;
            case KEY_D:
                g_fSpeedRight = 0.f;
                break;
            }
            dSetSpriteLinearVelocity("man", g_fSpeedLeft + g_fSpeedRight, g_fSpeedTop + g_fSpeedBottom);
            if((g_fSpeedLeft + g_fSpeedRight) > 0.f)
                dSetSpriteFlipX("man", 0);
            else if((g_fSpeedLeft + g_fSpeedRight) < 0.f)
                dSetSpriteFlipX("man", 1);
        }
    }
}
//===========================================================================
//
// �����뾫����ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
void OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
    if(strcmp(szSrcName, "man")==0&&strstr(szTarName, "wall")!=NULL)
    {
        float fVelX = -dGetSpriteLinearVelocityX("man");
        float fVelY = -dGetSpriteLinearVelocityY( "man" );
        dSetSpriteLinearVelocity("man", fVelX, fVelY);
    }
    if(strcmp(szSrcName, "man")==0&&strstr(szTarName, "heart")!=NULL)
    {
        dSpriteMoveTo( szTarName, fPosX, fPosY, 10, 1 );
        dSetSpriteScale( szTarName, 0.7 );
        dPlaySound("BLIP.wav",0,1);
        n++;
    }
    if(strcmp(szSrcName, "man")==0&&strcmp(szTarName, "end")==0)
    {
        flag=1;
    }
}
//===========================================================================
//
// ����������߽���ײ
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
     //iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
    //���û���˲���Խ������߽�
    if(strcmp(szName, "man")==0)
    {
        if(iColSide == 0) //���
        {
            //dSetSpriteFlipX("man", 1);
            dSetSpriteLinearVelocity("man", 0, 0);
        }
        else if(iColSide == 1)  // �ұ�
        {
            //dSetSpriteFlipX("man", 0);
            dSetSpriteLinearVelocity("man", 0, 0);
        }
        else if(iColSide == 2)   // �ϱ�
        {
            //dSetSpriteFlipX("man", 1);
            dSetSpriteLinearVelocity("man", 0, 0);
        }
        else if(iColSide == 3)  //�±�
        {
            //dSetSpriteFlipX("man", 0);
            dSetSpriteLinearVelocity("man", 0, 0);
        }
    }
}
