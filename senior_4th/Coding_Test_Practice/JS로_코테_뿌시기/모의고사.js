function solution(answers) {

    var answer = [];

    let f = [1, 2, 3, 4, 5]; //.length=5
    let s = [2, 1, 2, 3, 2, 4, 2, 5]; //.length=8
    let t = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]; //.length=10

    const result = [0, 0, 0];

    for (let i = 0; i < answers.length; i++) {
        if (f[i % f.length] == answers[i]) result[0]++;
        if (s[i % s.length] == answers[i]) result[1]++;
        if (t[i % t.length] == answers[i]) result[2]++;
    }

    const maxValue = Math.max(...result);

    let index = 0;
    for (let i = 0; i < 3; i++) {
        if (maxValue == result[i]) {
            answer[index] = i + 1;
            index++;
        }
    }

    return answer;
}