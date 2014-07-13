!include MUI2.nsh

Name "Capablanca"
OutFile "Capablanca-win32.exe"
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

	SetOutPath $INSTDIR\bin
	File /r bin\*
	
	SetOutPath $INSTDIR\help
	File /r help\*
	
	SetOutPath $INSTDIR
	createShortCut "$INSTDIR\Capablanca.lnk" "$INSTDIR\bin\Capablanca.exe"
	createShortCut "$INSTDIR\Uninstaller.lnk" "$INSTDIR\bin\uninstaller.exe"
	
	SetOutPath $SMPROGRAMS\Capablanca
	createShortCut "$SMPROGRAMS\Capablanca\Capablanca.lnk" "$INSTDIR\bin\Capablanca.exe"
	createShortCut "$SMPROGRAMS\Capablanca\Uninstall Capablanca.lnk" "$INSTDIR\bin\uninstaller.exe"
	
	SetOutPath $INSTDIR\bin
	WriteUninstaller "$INSTDIR\bin\uninstaller.exe"
SectionEnd ; "Install"

Section "Uninstall"
	SetOutPath $INSTDIR\..
	Delete $INSTDIR\..\bin\uninstaller.exe
	
	RMDir /r $INSTDIR\..\bin
	RMDir /r $INSTDIR\..\help
	
	Delete $INSTDIR\..\Capablanca.lnk
	Delete $INSTDIR\..\Uninstaller.lnk
	
	SetOutPath $INSTDIR\..\..
	RMDir $INSTDIR\..\bin ; bug? (directory structure)
	RMDir $INSTDIR\..\..\Capablanca ; Only remove if it is empty
	
	RMDir /r "$SMPROGRAMS\Capablanca"
SectionEnd ; "Uninstall"
