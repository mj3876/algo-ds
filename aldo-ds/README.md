# Git Bash에서 커밋하고 GitHub에 Push하기

이 문서는 작업한 파일을 확인하고, 커밋한 뒤, GitHub 원격 저장소의 `main` 브랜치로 푸시하는 방법을 설명합니다.

## 1. 프로젝트 폴더로 이동

Git Bash를 열고 다음 명령어를 실행합니다.

```bash
cd /c/Users/ms840/mjuser/aldo-ds
```

현재 위치를 확인하려면 다음 명령어를 사용합니다.

```bash
pwd
```

> 이 프로젝트는 상위 폴더에 있는 Git 저장소에 포함되어 있습니다. 다른 폴더의 파일이 함께 추가되지 않도록 반드시 `aldo-ds` 폴더에서 명령어를 실행하세요.

## 2. 변경된 파일 확인

```bash
git status
```

변경 내용을 자세히 확인하고 싶다면 다음 명령어를 실행합니다.

```bash
git diff
```

## 3. 커밋할 파일 추가

현재 `aldo-ds` 폴더에서 변경한 파일을 모두 추가합니다.

```bash
git add .
```

특정 파일만 추가하려면 파일 경로를 지정합니다.

```bash
git add README.md
```

추가된 파일을 확인합니다.

```bash
git status
```

## 4. 커밋 생성

변경 내용을 짧고 명확하게 설명하는 메시지를 작성합니다.

```bash
git commit -m "README에 Git push 가이드 추가"
```

커밋 메시지 예시:

```bash
git commit -m "알고리즘 문제 풀이 추가"
git commit -m "정렬 알고리즘 코드 수정"
git commit -m "테스트 코드 추가"
```

## 5. 원격 저장소의 최신 내용 가져오기

로컬 커밋을 만든 뒤 원격 `main` 브랜치의 최신 내용을 반영합니다.

```bash
git pull --rebase origin main
```

## 6. GitHub에 Push

```bash
git push origin main
```

현재 브랜치가 이미 `origin/main`을 추적하고 있으므로 다음과 같이 짧게 실행할 수도 있습니다.

```bash
git push
```

## 자주 사용하는 전체 순서

```bash
cd /c/Users/ms840/mjuser/aldo-ds
git status
git add .
git status
git commit -m "변경 내용 요약"
git pull --rebase origin main
git push origin main
```

## 자주 발생하는 상황

### `nothing to commit`이 표시되는 경우

커밋할 변경 사항이 없거나, 파일을 저장하지 않은 상태입니다. 파일을 저장한 뒤 `git status`를 다시 실행합니다.

### Push가 거부되는 경우

원격 저장소에 새로운 커밋이 있을 수 있습니다. 최신 내용을 가져온 뒤 다시 푸시합니다.

```bash
git pull --rebase origin main
git push origin main
```

### 충돌(conflict)이 발생한 경우

충돌이 표시된 파일을 직접 수정하고 저장한 뒤 다음 명령어를 실행합니다.

```bash
git add <충돌을 해결한 파일>
git rebase --continue
git push origin main
```

진행 중인 rebase를 취소하고 이전 상태로 돌아가려면 다음 명령어를 사용합니다.

```bash
git rebase --abort
```

### GitHub 로그인을 요구하는 경우

HTTPS 방식으로 푸시할 때는 GitHub 계정 비밀번호 대신 브라우저 로그인, Git Credential Manager 또는 Personal Access Token(PAT)을 사용합니다.

## 최초 사용자 정보 설정

Git을 처음 사용하는 컴퓨터라면 이름과 이메일을 한 번 설정합니다.

```bash
git config --global user.name "GitHub 사용자 이름"
git config --global user.email "GitHub에 등록한 이메일"
```

설정값은 다음 명령어로 확인할 수 있습니다.

```bash
git config --global --list
```
