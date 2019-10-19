; Define your application name
!define APPNAME "trab2FT"
!define APPNAMEANDVERSION "trab2FT 1.0.1"

; Main Install settings
Name "${APPNAMEANDVERSION}"
InstallDir "$PROGRAMFILES\trab2FT"
InstallDirRegKey HKLM "Software\${APPNAME}" ""
OutFile ".\trab2FT_1.0.1.exe"

; Use compression
SetCompressor LZMA

; Modern interface settings
!include "MUI.nsh"

!define MUI_ABORTWARNING
!define MUI_FINISHPAGE_RUN "$INSTDIR\trab2FT.exe"

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

; Set languages (first is default language)
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_RESERVEFILE_LANGDLL

Section "trab2FT" Section1

	; Set Section properties
	SetOverwrite on

	; Set Section Files and Shortcuts
	SetOutPath "$INSTDIR\"
	File "..\bin\trab2FT.exe"
	File "..\bin\mingwm10.dll"
	File "..\bin\QtCore4.dll"
	File "..\bin\QtGui4.dll"
	File "..\CHANGELOG.txt"
	CreateShortCut "$DESKTOP\trab2FT.lnk" "$INSTDIR\trab2FT.exe"
	CreateDirectory "$SMPROGRAMS\trab2FT"
	CreateShortCut "$SMPROGRAMS\trab2FT\trab2FT.lnk" "$INSTDIR\trab2FT.exe"
	CreateShortCut "$SMPROGRAMS\trab2FT\Uninstall.lnk" "$INSTDIR\uninstall.exe"
	

SectionEnd

Section -FinishSection

	WriteRegStr HKLM "Software\${APPNAME}" "" "$INSTDIR"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "DisplayName" "${APPNAME}"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "UninstallString" "$INSTDIR\uninstall.exe"
	WriteUninstaller "$INSTDIR\uninstall.exe"

SectionEnd

; Modern install component descriptions
!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
	!insertmacro MUI_DESCRIPTION_TEXT ${Section1} ""
!insertmacro MUI_FUNCTION_DESCRIPTION_END

;Uninstall section
Section Uninstall

	;Remove from registry...
	DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}"
	DeleteRegKey HKLM "SOFTWARE\${APPNAME}"

	; Delete self
	Delete "$INSTDIR\uninstall.exe"

	; Delete Shortcuts
	Delete "$DESKTOP\trab2FT.lnk"
	Delete "$SMPROGRAMS\trab2FT\trab2FT.lnk"
	Delete "$SMPROGRAMS\trab2FT\Uninstall.lnk"

	; Clean up grandOthello
	Delete "$INSTDIR\trab2FT.exe"
	Delete "$INSTDIR\mingwm10.dll"
	Delete "$INSTDIR\QtCore4.dll"
	Delete "$INSTDIR\QtGui4.dll"
	Delete "$INSTDIR\CHANGELOG.txt"

	; Remove remaining directories
	RMDir "$SMPROGRAMS\trab2FT"
	RMDir "$INSTDIR\"

SectionEnd

; eof
