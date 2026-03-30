# 🧩 UE5 Custom Module & Plugin Practice

이 프로젝트는 언리얼 엔진 5(Unreal Engine 5)의 핵심 빌드 구조인 **모듈(Module)**과 **플러그인(Plugin)**을 수동으로 구축하고 연결하는 방법을 실습한 프로젝트입니다. 

단순히 메인 모듈에 코드를 집중시키는 것을 넘어, 기능을 독립적인 모듈과 플러그인으로 분리하여 **코드의 재사용성**을 높이고 **협업에 유리한 구조**를 설계하는 데 목적이 있습니다.

## 🚀 구현 기능 (Features)

* **Custom Game Module (`TestLogModule`)**
  * `Source` 폴더 내에 메인 게임 모듈과 분리된 독립적인 C++ 모듈 구축
  * `Build.cs` 설정을 통한 모듈 간 종속성(Dependency) 및 컴파일 타겟 연결
  * `TESTLOGMODULE_API` 매크로를 활용한 클래스 외부 노출(Export)

* **Standalone Plugin (`TestLogPlugin`)**
  * 다른 언리얼 프로젝트에 즉시 이식 가능한 재사용 가능한 플러그인 구조 구축
  * `.uplugin` 메타데이터 작성 및 플러그인 내부 전용 C++ 모듈(`TestLogPlugin`) 세팅
  * 콘텐츠 브라우저에서 플러그인 에셋 및 C++ 클래스 활성화

* **모듈 간 상호작용 및 검증**
  * 메인 모듈의 캐릭터(`Character.cpp`) 런타임(`BeginPlay`) 시, 분리된 모듈과 플러그인의 커스텀 액터(`ATestActor`, `APluginTestActor`)를 동적 스폰(Spawn)
  * 각 액터가 정상적으로 메모리에 적재되고 작동하는지 출력 로그(Output Log)를 통해 검증

## 📂 핵심 폴더 구조 (Project Structure)

```text
MyModuleAndPlugin/
 ┣ 📁 Plugins/
 ┃  ┗ 📁 TestLogPlugin/                  # 재사용 가능한 독립 플러그인
 ┃     ┣ 📄 TestLogPlugin.uplugin        # 플러그인 메타데이터 및 모듈 정의
 ┃     ┗ 📁 Source/
 ┃        ┗ 📁 TestLogPlugin/            # 플러그인 내부 C++ 모듈
 ┃           ┣ 📄 TestLogPlugin.Build.cs
 ┃           ┗ 📄 PluginTestActor.cpp    # 플러그인 테스트용 액터
 ┣ 📁 Source/
 ┃  ┣ 📁 MyModuleAndPlugin/              # 메인 게임 모듈 (Primary Game Module)
 ┃  ┃  ┣ 📄 MyModuleAndPlugin.Build.cs   # TestLogModule 및 TestLogPlugin 종속성 추가
 ┃  ┃  ┗ 📄 MyModuleAndPluginCharacter.cpp # 외부 액터 스폰 로직 구현
 ┃  ┗ 📁 TestLogModule/                  # 사용자 정의 게임 모듈
 ┃     ┣ 📄 TestLogModule.Build.cs
 ┃     ┗ 📄 TestActor.cpp                # 모듈 테스트용 액터
 ┣ 📄 MyModuleAndPlugin.Target.cs        # 빌드 타겟 설정 (새 모듈 포함)
 ┣ 📄 MyModuleAndPluginEditor.Target.cs
 ┗ 📄 MyModuleAndPlugin.uproject         # 프로젝트 로드 시 모듈 및 플러그인 활성화 설정
