# [Silver I] 정렬 - 17074 

[문제 링크](https://www.acmicpc.net/problem/17074) 

### 성능 요약

메모리: 2800 KB, 시간: 16 ms

### 분류

많은 조건 분기, 다이나믹 프로그래밍

### 제출 일자

2025년 7월 24일 01:15:27

### 문제 설명

<p>정렬이란, 배열의 모든 원소가 비내림차순이 되도록 순서를 바꾸는 것을 말한다. 예를 들어 배열 [2, 1, 2, 3, 1]을 정렬하면 [1, 1, 2, 2, 3]이 된다.</p>

<p>남규는 정수 <em>N</em>개로 이루어진 배열 하나를 갖고 있다. 이 배열에서, 남규는 맘에 들지 않는 수를 정확히 하나 골라서 버릴 것이다.</p>

<p>예를 들어, 남규가 가진 배열이 [1, 2, 3, 2]라면, 남규는 1을 버려 [2, 3, 2]를 만들거나, 첫 2를 버려 [1, 3, 2]를 만들거나, 3을 버려 [1, 2, 2]를 만들거나, 두 번째 2를 버려 [1, 2, 3]을 만들 수 있다. 그리고 네 가지 경우 중 결과가 정렬된 것은 [1, 2, 2]와 [1, 2, 3] 두 가지이다. 남규는 이처럼, 수 하나를 버린 뒤 결과 배열이 정렬되어 있기를 원한다.</p>

<p>남규가 갖고 있는 배열이 주어지면, 수 하나를 버려 정렬된 배열을 남기는 방법의 수를 구해보도록 하자.</p>

### 입력 

 <p>첫째 줄에 배열의 크기 <em>N</em>이 주어진다. (2 ≤ <em>N</em> ≤ 10<sup>5</sup>)</p>

<p>둘째 줄에 배열의 원소<em> a<sub>i</sub></em>가 공백으로 구분되어 <em>N</em>개 주어진다. (-10<sup>9</sup> ≤ <em>a<sub>i</sub></em> ≤ 10<sup>9</sup>)</p>

### 출력 

 <p>남규가 수 하나를 버려 정렬된 배열을 만드는 경우의 수를 출력한다.</p>

