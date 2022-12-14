/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _LESSON_X_H_
#define _LESSON_X_H_
//
#include <Windows.h>

extern void	GameMainLoop( float	fDeltaTime );
extern void OnMouseMove( const float fMouseX, const float fMouseY );
extern void OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
extern void OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
extern void OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );
extern void OnKeyUp( const int iKey );
extern void OnSpriteColSprite( const char *szSrcName, const char *szTarName );
extern void OnSpriteColWorldLimit( const char *szName, const int iColSide );

extern int 	dIsPointInSprite( const char *szName, const float fPosX, const float fPosY );

extern void	gameMainLoop( float	fDeltaTime );
extern void onMouseMove( const float fMouseX, const float fMouseY );
extern void onMouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
extern void onMouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
extern void onKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );
extern void onKeyUp( const int iKey );
extern void onSpriteColSprite( const char *szSrcName, const char *szTarName );
extern void onSpriteColWorldLimit( const char *szName, const int iColSide );

extern int 	DIsPointInSprite( const char *szName, const float fPosX, const float fPosY );

extern void	gAmeMainLoop( float	fDeltaTime );
extern void oNMouseMove( const float fMouseX, const float fMouseY );
extern void oNMouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
extern void oNMouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
extern void oNKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );
extern void oNKeyUp( const int iKey );
extern void oNSpriteColSprite( const char *szSrcName, const char *szTarName );
extern void oNSpriteColWorldLimit( const char *szName, const int iColSide );
#endif // _LESSON_X_H_
