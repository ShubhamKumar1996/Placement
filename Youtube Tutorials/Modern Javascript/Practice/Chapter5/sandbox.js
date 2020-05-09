const paras = document.querySelectorAll("p");

paras.forEach(para=>{
    let str = para.innerText;
    console.log(str);
    
    let flag = 0; 
    let s = "";
    for(let i=0;i<str.length;i++){
        if(str[i]!=" "){
            s  += str[i]; continue;
        }
        console.log(s);
        if(s=="success"){
            flag = 1;
            break;
        }
        if(s=="error"){
            flag = -1;
            break;
        }
        s = "";
    }
    if(s!="" && flag===0){
        if(s=="success"){
            flag = 1;
        }
        if(s=="error"){
            flag = -1;
        }
    }
    
    if(flag===1){
        para.setAttribute("class", "success");
    }
    else if(flag===-1){
        para.setAttribute("class", "error");
    }
    else if(flag===0){
        para.setAttribute("class", "neutral");
    }
    
});