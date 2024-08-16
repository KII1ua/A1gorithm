def solution(numbers):
    result = set()
    for i in range(len(numbers)):
        for j in range(i+1, len(numbers)):
            result.add(numbers[i] + numbers[j])
    result = list(result)
    result.sort()
    return result