function findAllHobbyists(hobby, hobbies) {

    for (var person in hobbies) {
        console.log(hobbies[person]);
    }
    return [];
}

var hobbies = {
    "Steve": ['Fashion', 'Piano', 'Reading'],
    "Patty": ['Drama', 'Magic', 'Pets'],
    "Chad": ['Puzzles', 'Pets', 'Yoga']
};

console.log(findAllHobbyists('Yoga', hobbies));