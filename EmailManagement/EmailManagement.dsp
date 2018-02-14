# Microsoft Developer Studio Project File - Name="EmailManagement" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=EmailManagement - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "EmailManagement.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "EmailManagement.mak" CFG="EmailManagement - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "EmailManagement - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "EmailManagement - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "EmailManagement - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "EmailManagement - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 SkinPPWTL.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "EmailManagement - Win32 Release"
# Name "EmailManagement - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AllUsersDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BlurFindDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ContactManagement.cpp
# End Source File
# Begin Source File

SOURCE=.\DBConnDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EmailContactGroupDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EmailDraftDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EmailManagement.cpp
# End Source File
# Begin Source File

SOURCE=.\EmailManagement.rc
# End Source File
# Begin Source File

SOURCE=.\EmailManagementDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EmailRecordDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EmailTypeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MyEmailSendDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TimeQueryDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\UserLogon.cpp
# End Source File
# Begin Source File

SOURCE=.\UserRegistDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AllUsersDlg.h
# End Source File
# Begin Source File

SOURCE=.\Base64Date6.h
# End Source File
# Begin Source File

SOURCE=.\BlurFindDlg.h
# End Source File
# Begin Source File

SOURCE=.\ContactManagement.h
# End Source File
# Begin Source File

SOURCE=.\DBConnDlg.h
# End Source File
# Begin Source File

SOURCE=.\EmailContactGroupDlg.h
# End Source File
# Begin Source File

SOURCE=.\EmailDraftDlg.h
# End Source File
# Begin Source File

SOURCE=.\EmailManagement.h
# End Source File
# Begin Source File

SOURCE=.\EmailManagementDlg.h
# End Source File
# Begin Source File

SOURCE=.\EmailRecordDlg.h
# End Source File
# Begin Source File

SOURCE=.\EmailTypeDlg.h
# End Source File
# Begin Source File

SOURCE=.\MyEmailSendDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SkinPPWTL.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TimeQueryDlg.h
# End Source File
# Begin Source File

SOURCE=.\UserLogon.h
# End Source File
# Begin Source File

SOURCE=.\UserRegistDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\EmailManagement.ico
# End Source File
# Begin Source File

SOURCE=.\res\EmailManagement.rc2
# End Source File
# Begin Source File

SOURCE=.\res\icon.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\Debug\CImage2008.dll
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
