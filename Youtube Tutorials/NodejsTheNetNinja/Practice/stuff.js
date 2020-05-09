let counter1 =(arr)=>{
    let count = 0;
    for(let i = 0;i < arr.length; i++){
        count++;
    }
    return "Length of array:"+count ;
};

let counter2 =(arr)=>{
    let count = 0;
    for(let i = 0;i < arr.length; i++){
        count++;
    }
    return "Length of array:"+count ;
};

module.exports = {
    counter1: counter1,
    counter2: counter2
};
