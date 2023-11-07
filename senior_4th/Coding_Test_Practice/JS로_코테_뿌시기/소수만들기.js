//조합 구하는 함수
const getCombinations = function (arr, selectNumber) {

    const results = [];

    if (selectNumber === 1) return arr.map((value) => [value]);


    arr.forEach((fixed, index, origin) => {

        const rest = origin.slice(index + 1);
        const combinations = getCombinations(rest, selectNumber - 1);
        const attached = combinations.map((combination) => [fixed, ...combination]);

        results.push(...attached);

    });

    return results;

}

//소수인지 판별하는 함수
function isPrime(num) {
    for (let i = 2; num > i; i++) {
        if (num % i === 0) {
            return false;
        }
    }
    return num > 1;
}


function solution(nums) {
    let answer = 0;
    let result = getCombinations(nums, 3);

    for (let items in result) {
        let sum = 0;
        for (let i = 0; i < 3; i++) {
            sum += result[items][i];
        }
        if (isPrime(sum)) answer++;
    }

    return answer;
}