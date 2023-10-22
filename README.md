# Operating_System

### OS_project01
Linux의 명령어 실행을 통한 운영체제 기본 개념 이해 (보고서 작성)

### OS_project02
간단한 Shell 및 기본 명령어 구현

1. 과제 목표
    - Linux에서 기본적으로 제공하는 bash 쉘과 유사한 간단한 SSUShell 구현
    - 운영체제의 프로세스 관리 기본 개념 이해
    - 시스템 호출 함수를 이용하여 간단한 프로그램 작성 기법 이해
      * Linux의 간단한 내장 명렁어(echo, cat, sleep, ls, ps, top, grep 등) 기능 이해
      * Linux의 간단한 내장 명령어와 유사한 명령어(pps, ttop) 구현

2. 기본 지식
    - Linux의 프로세스 관련 시스템 호출 함수 (fork, exec, exit, wait 등)

3. 과제 내용
    - Linux 설치
    - Linux 내장 명령어를 실행하는 간단한 쉘 (SSUShell) 구현
    - 쉘 명령어 ttop(top), pps(ps) 구현

### OS_project03
xv6에서 시스템 호출 추가 및 스케쥴러 수정

* 과제 목표
   - xv6의 프로세스 관리와 스케쥴링 기법 이해
   - xv6에서 시스템 호출 추가 및 기존 스케쥴러 변경

* 기본 지식
   - 시스템 호출 추가 방법 이해
   - 특정 시스템 호출은 인자가 없고 정수값만을 리턴
   - 특정부 시스템 호출은 문자열 및 정수 등, 여러 인수를 받아 간단한 정수 값을 리턴
   - 특정 시스템 호출은 여러 정보를 사용자가 정의한 구조체로 사용자 프로그램에 리턴
   - Cross Compile 방법 학습
   - xv6 커널 이해
       * user.h : xv6의 시스템 호출 정의
       * usys.S : xv6의 시스템 호출 리스트
       * syscall.h : 시스템 호출 번호 매핑 -> 새 시스템 호출을 위해 새로운 매핑 추가
       * syscall.c : 시스템 호출 인수를 구문 분석하는 함수 및 실제 시스템 호출 구현에 대한 포인터
       * sysproc.c : 프로세스 관련 시스템 호출 구현. -> 여기에 시스템 호출 코드를 추가
       * proc.h는 struct proc 구조 정의 -> 프로세스에 대한 추가 정보를 추적을 위해 구조 변경
       * proc.c : 프로세스간의 스케쥴링 및 컨텍스트 전환을 수행하는 함수

* 과제 내용
    0. xv6 및 qeumu 다운로드 및 설치
    1. 새로운 시스템 호출 추가 및 간단한 응용 프로그램 구현
        - hello() 시스템 호출 추가 및 이를 호출하는 주어진 간단한 응용 프로그램 실행
        - hello_name() 시스템 호출 추가 및 이를 호출하는 간단한 응용 프로그램 구현
        - get_num_proc() 시스템 호출 추가 및 이를 호출하는 간단한 응용 프로그램 구현
        - get_max_pid() 시스템 호출 추가 및 이를 호출하는 간단한 응용 프로그램 구현
        - get_proc_info(pid, *processInfo) 시스템 호출 추가 및 간단한 응용 프로그램 구현
     2. 새로운 스케쥴러를 위한 2개의 시스템 호출 추가
     3. 우선순위 기반 RR 스케쥴러 구현
     4. 새로운 스케쥴러를 테스트 및 검증

### OS_project04
Pthread
* 과제 목표
  - 다중 쓰레드 프로그래밍의 기본 개념을 이해
  - lock 및 조건 변수를 사용하는 쓰레드(pthread) 프로그램 구현

* 기본지식
  - pthread 사용자 수준 쓰레드 라이브러리
  - 다중 쓰레드로 구현된 시스템의 일반적인 형태

* 과제 기본 내용
  - 많은 응용에서 볼 수 있는 간단한 마스터 및 워커 스레드 풀을 구현
  - 읽기-쓰기 Locks을 통한 쓰레드 간 병행성 향상 프로그램 구현
  - pthread를 이용한 사용자 수준의 SSU_세마포어 구현

* 과제 구현 내용
  1. Master-Worker Thread Pool 구현
  2. Reader-Writer Locks 쓰레드 프로그램 구현
  3. pthread를 이용한 사용자 수준 세마포어(SSU_Sem) 구현

### OS_project05
동적 메모리 관리

* 과제 목표
  - 프로그램에서 메모리를 동적으로 할당하는 사용자 지정 메모리 관리자를 구현
  - malloc(3) 및 free(3)와 같은 C 라이브러리 함수를 대체하는 역할을 하는 메모리 할당하고 해제하는 함수 구현을 통해 메모리 관리 기법 이해

* 기본 지식
  - Linux의 프로세스 관련 시스템 호출 함수(mmap(2), munmap(2) 등)

* 과제 내용 기본
  - mmap(2)을 사용하여 OS가 메모리 페이지를 가져오고, 메모리를 요청 시 메모리 페이지들의 chunk를 동적으로 할당
  - 사용자 입력을 위해 잠시 중지하거나 sleep()등으로 오랫 시간 동안 실행되는 간단한 C 프로그램을 작성하고 실행
  - 작성된 간단한 C 프로그램에 OS의 빈 페이지를 메모리 맵에 추가하는 코드를 수정 구현하고 수정한 간단한 C 프로그램을 일시 중지하여 해당 프로세스에서 사용하는 가상 및 실제 메모리를 측정
  - 마지막으로 일부 데이터를 memory mapped 페이지에 쓰고 가상 및 실제 메모리 사용량을 다시 측정

* 과제 구현 내용
  1. 간단한 메모리 관리자(동적으로 메모리 할당 및 해제) 구현
  2. 확장 가능한 Heap

### OS_project06
파일 시스템

* 과제 목표
  - 가상 디스크(애뮬레이터)를 위한 간단한 파일 시스템 및 기본 파일 operation 구현
  - 디스크 접근 기능이 구현된 ssufs-disk.h와 ssufs-disk.c에서 정의(구현된)된 여러 함수를 이용하여, ssufs-ops.c를 수정(ssufs_create(), ssufs_delete(), ssufs_read(), ssufs_write() 구현)

* 기본 지식
  - 가상 디스크
  - inode 구조체
  - ssu_disk.c에 구현된 함수 설명

* 과제 기본 내용
  - 기본 지식에서 설명한 함수를 이용하여 과제 구현 내용의 기능 구현 (ssufs-ops.h 확인 및 ssufs-ops.c 수정)
  - ssu-disk.h : file handle 배열이라고 하는 메모리 내 데이터 구조를 정의함
  - Linux 및 Unix 시스템과 달리 create()와 open()은 별도로 구현

* 과제 구현 내용
  1. int ssufs_create(char * filename)
  2. void ssufs_delete(char * filename)
  3. int ssufs_open(char * filename)
  4. void ssufs_close(int file handle)
  5. int ssufs_read(int file handle, char * buf, int nbytes)
  6. int ssufs_write(int file handle, char * buf, int nbytes)
  7. int ssufs_lseek(int file handle, int nseek)