# [Gold V] 산업 스파이의 편지 - 3671 

[문제 링크](https://www.acmicpc.net/problem/3671) 

### 성능 요약

메모리: 11928 KB, 시간: 100 ms

### 분류

브루트포스 알고리즘, 조합론, 수학, 정수론, 소수 판정, 에라토스테네스의 체

### 제출 일자

2025년 4월 11일 16:07:07

### 문제 설명

<p>안녕하세요. 저는 산업 스파이입니다. 저의 정체를 절대 다른 사람에게 말하지 말아주세요.</p>

<p>저의 가장 최근 일은 유명한 수학 연구소의 최신 연구 결과를 훔쳐오는 것이었습니다. 저는 매우 유능한 산업 스파이이기 때문에, 연구 결과를 어렵지 않게 얻을 수 있었습니다. 하지만, 제가 올 것을 미리 알았는지 연구소에서는 연구 결과를 모두 서류 절단기에 넣어버렸습니다. 어쩔수 없이 저는 눈물을 머금고 종이 조각을 모두 훔쳐왔습니다.</p>

<p>저를 고용한 사람은 매우 무서운 사람입니다. 또, 저는 프로이기 때문에 실수를 용납하지 않습니다. 어떻게든 이 종이를 모두 복구해가야합니다. 이 연구소의 연구 주제는 빠른 소인수 분해입니다. 제가 가진 종이 조각에는 숫자가 한 자리씩만 적혀져 있습니다. 원래 숫자가 뭐였는지를 잘 모르겠습니다. 종이 조각에 쓰여 있는 숫자를 보내드릴테니, 종이 조각을 적절히 배치해서 소수가 되는 경우가 몇 개이지 알려주실 수 있나요?</p>

<p>감사합니다.</p>

<p>스파이 드림.</p>

### 입력 

 <p>첫째 줄에 테스트 케이스의 개수 c가 주어진다. (1 ≤ c ≤ 200) 각 테스트 케이스는 한 줄로 이루어져 있고, 종이조각에 쓰여 있는 수가 공백없이 주어진다. 종이조각의 수는 적어도 1개, 많아야 7개이다.</p>

### 출력 

 <p>각 테스트 케이스에 대해 종이조각을 적절히 배치해서 만들 수 있는 서로 다른 소수의 개수를 출력한다. 이때, 모든 종이 조각을 사용하지 않아도 된다. (7과 1이 있을 때, 만들 수 있는 소수는 7, 17, 71이다) 종이 조각을 적절히 배치해서 만든 숫자가 0으로 시작할 때, 앞에있는 0을 지운 수가 같으면 같은 숫자이다.</p>

