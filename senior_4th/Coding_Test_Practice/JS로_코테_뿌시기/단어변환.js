function can_change(w1, w2){
    
    let diff=0;
    for(let i=0; i<w1.length; i++){
        if(w1[i]!==w2[i]) diff++;
    }
    if(diff==1) return true;
    else return false;
    
}
function solution(begin, target, words) {
    
    let answer = 0;
    
    let visited = new Array(words.length);
    visited.fill(false);
    
    dfs(begin, 0);
    
    function dfs(cur_word, level){
        if(cur_word===target){
            if(answer>level||answer===0) answer=level;
            return;
        }
        
        for(let i=0; i<words.length; i++){
            
            if(cur_word===words[i]) continue;
            
            if(can_change(cur_word,words[i])&&!visited[i]){
                visited[i]=true;
                dfs(words[i],level+1);
                visited[i]=false;
            }
        }
    }
    
    return answer;
}