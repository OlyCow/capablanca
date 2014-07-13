!include MUI2.nsh

Name "Capablanca"
OutFile "Capablanca-wineskin32.exe"
; CHANGE DIRECTORY TO PROGRAM FILES FOR RELEASE!!!
InstallDir "$DESKTOP\Capablanca"
RequestExecutionLevel admin

!define MUI_ABORT_WARNING
!define MUI_UNABORT_WARNING

!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

!insertmacro MUI_LANGUAGE "English"

Section "Install"
	setAutoClose false

	SetOutPath $INSTDIR
	File /x *.nsh *
	
	; DIRECTORY CURRENTLY EMPTY
	; SetOutPath $INSTDIR\plugins
	; File /r plugins\*
	
	SetOutPath $INSTDIR\platforms
	File /r platforms\*
	
	SetOutPath $INSTDIR\help
	File /r help\*
	
	SetOutPath $INSTDIR
	createShortCut "$INSTDIR\Capablanca.lnk" "$INSTDIR\Capablanca.exe"
	createShortCut "$INSTDIR\Uninstaller.lnk" "$INSTDIR\uninstaller.exe"
	
	SetOutPath $SMPROGRAMS\Capablanca
	createShortCut "$SMPROGRAMS\Capablanca\Capablanca.lnk" "$INSTDIR\Capablanca.exe"
	createShortCut "$SMPROGRAMS\Capablanca\Uninstall Capablanca.lnk" "$INSTDIR\uninstaller.exe"
	
	SetOutPath $INSTDIR
	WriteUninstaller "$INSTDIR\uninstaller.exe"
SectionEnd ; "Install"

Section "Uninstall"
	SetOutPath $INSTDIR
	Delete $INSTDIR\uninstaller.exe
	
	RMDir /r "$SMPROGRAMS\Capablanca"
SectionEnd ; "Uninstall"
