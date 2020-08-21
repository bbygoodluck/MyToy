##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=SnowBall
ConfigurationName      :=Release
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=F:/MyData/Programming/MyProject/C++/CodeLite/MyToy
ProjectPath            :=F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/SnowBall
IntermediateDirectory  :=../build-$(ConfigurationName)/SnowBall
OutDir                 :=../build-$(ConfigurationName)/SnowBall
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=81112580
Date                   :=21/08/2020
CodeLitePath           :=E:/Tools/Programming/CodeLite
LinkerName             :=F:/MyData/Programming/C++/gcc/mingw-64_gcc_10.1.0/bin/x86_64-w64-mingw32-g++.exe
SharedObjectLinkerName :=F:/MyData/Programming/C++/gcc/mingw-64_gcc_10.1.0/bin/x86_64-w64-mingw32-g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := $(shell wx-config --rcflags)
RcCompilerName         :=F:/MyData/Programming/C++/gcc/mingw-64_gcc_10.1.0/bin/windres.exe
LinkOptions            :=  -mwindows  $(shell wx-config --debug=no --libs --unicode=yes)
IncludePath            :=  $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := F:/MyData/Programming/C++/gcc/mingw-64_gcc_10.1.0/bin/x86_64-w64-mingw32-gcc-ar.exe rcu
CXX      := F:/MyData/Programming/C++/gcc/mingw-64_gcc_10.1.0/bin/x86_64-w64-mingw32-g++.exe
CC       := F:/MyData/Programming/C++/gcc/mingw-64_gcc_10.1.0/bin/x86_64-w64-mingw32-gcc.exe
CXXFLAGS :=  -O2 -Wall $(shell wx-config --cxxflags --unicode=yes --debug=no) $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(shell wx-config --cxxflags --unicode=yes --debug=no) $(Preprocessors)
ASFLAGS  := 
AS       := F:/MyData/Programming/C++/gcc/mingw-64_gcc_10.1.0/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
WXWIN:=F:\MyData\Programming\Lib\wxWidgets-3.1.3
WXCFG:=/gcc_dll/mswu
Objects0=../build-$(ConfigurationName)/SnowBall/src_view_SnowBallView.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/SnowBall/src_view_Snow.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/SnowBall/src_resource_resource.rc$(ObjectSuffix) ../build-$(ConfigurationName)/SnowBall/src_PanelSnowBall.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/SnowBall/src_MainFrame.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/SnowBall/src_SnowBall.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/SnowBall/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\SnowBall" mkdir "..\build-$(ConfigurationName)\SnowBall"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\SnowBall" mkdir "..\build-$(ConfigurationName)\SnowBall"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/SnowBall/.d:
	@if not exist "..\build-$(ConfigurationName)\SnowBall" mkdir "..\build-$(ConfigurationName)\SnowBall"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/SnowBall/src_view_SnowBallView.cpp$(ObjectSuffix): src/view/SnowBallView.cpp ../build-$(ConfigurationName)/SnowBall/src_view_SnowBallView.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/SnowBall/src/view/SnowBallView.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_view_SnowBallView.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/SnowBall/src_view_SnowBallView.cpp$(DependSuffix): src/view/SnowBallView.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/SnowBall/src_view_SnowBallView.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/SnowBall/src_view_SnowBallView.cpp$(DependSuffix) -MM src/view/SnowBallView.cpp

../build-$(ConfigurationName)/SnowBall/src_view_SnowBallView.cpp$(PreprocessSuffix): src/view/SnowBallView.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/SnowBall/src_view_SnowBallView.cpp$(PreprocessSuffix) src/view/SnowBallView.cpp

../build-$(ConfigurationName)/SnowBall/src_view_Snow.cpp$(ObjectSuffix): src/view/Snow.cpp ../build-$(ConfigurationName)/SnowBall/src_view_Snow.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/SnowBall/src/view/Snow.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_view_Snow.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/SnowBall/src_view_Snow.cpp$(DependSuffix): src/view/Snow.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/SnowBall/src_view_Snow.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/SnowBall/src_view_Snow.cpp$(DependSuffix) -MM src/view/Snow.cpp

../build-$(ConfigurationName)/SnowBall/src_view_Snow.cpp$(PreprocessSuffix): src/view/Snow.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/SnowBall/src_view_Snow.cpp$(PreprocessSuffix) src/view/Snow.cpp

../build-$(ConfigurationName)/SnowBall/src_resource_resource.rc$(ObjectSuffix): src/resource/resource.rc
	$(RcCompilerName) -i "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/SnowBall/src/resource/resource.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/src_resource_resource.rc$(ObjectSuffix) $(RcIncludePath)
../build-$(ConfigurationName)/SnowBall/src_PanelSnowBall.cpp$(ObjectSuffix): src/PanelSnowBall.cpp ../build-$(ConfigurationName)/SnowBall/src_PanelSnowBall.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/SnowBall/src/PanelSnowBall.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_PanelSnowBall.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/SnowBall/src_PanelSnowBall.cpp$(DependSuffix): src/PanelSnowBall.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/SnowBall/src_PanelSnowBall.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/SnowBall/src_PanelSnowBall.cpp$(DependSuffix) -MM src/PanelSnowBall.cpp

../build-$(ConfigurationName)/SnowBall/src_PanelSnowBall.cpp$(PreprocessSuffix): src/PanelSnowBall.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/SnowBall/src_PanelSnowBall.cpp$(PreprocessSuffix) src/PanelSnowBall.cpp

../build-$(ConfigurationName)/SnowBall/src_MainFrame.cpp$(ObjectSuffix): src/MainFrame.cpp ../build-$(ConfigurationName)/SnowBall/src_MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/SnowBall/src/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_MainFrame.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/SnowBall/src_MainFrame.cpp$(DependSuffix): src/MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/SnowBall/src_MainFrame.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/SnowBall/src_MainFrame.cpp$(DependSuffix) -MM src/MainFrame.cpp

../build-$(ConfigurationName)/SnowBall/src_MainFrame.cpp$(PreprocessSuffix): src/MainFrame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/SnowBall/src_MainFrame.cpp$(PreprocessSuffix) src/MainFrame.cpp

../build-$(ConfigurationName)/SnowBall/src_SnowBall.cpp$(ObjectSuffix): src/SnowBall.cpp ../build-$(ConfigurationName)/SnowBall/src_SnowBall.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/MyData/Programming/MyProject/C++/CodeLite/MyToy/SnowBall/src/SnowBall.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_SnowBall.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/SnowBall/src_SnowBall.cpp$(DependSuffix): src/SnowBall.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/SnowBall/src_SnowBall.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/SnowBall/src_SnowBall.cpp$(DependSuffix) -MM src/SnowBall.cpp

../build-$(ConfigurationName)/SnowBall/src_SnowBall.cpp$(PreprocessSuffix): src/SnowBall.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/SnowBall/src_SnowBall.cpp$(PreprocessSuffix) src/SnowBall.cpp


-include ../build-$(ConfigurationName)/SnowBall//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


