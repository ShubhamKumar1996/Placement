import React from 'react';
/*
const Ninjas = (props) => {
    const { ninjas, deleteNinja } = props;
    const ninjaList = ninjas.map(ninja => {
        if(ninja.age > 23){
            return (
                <div className="ninja" key={ninja.id}>
                <div>Name: {ninja.name}</div>
                <div>Age: {ninja.age}</div>
                <div>Belt: {ninja.belt}</div>
            </div>
            )
        }
        return null;
    });
    */
const Ninjas = (props) => {
    const { ninjas, deleteNinja } = props;
    const ninjaList = ninjas.map(ninja => {
       return (ninja.age > 23)? (
        <div className="ninja" key={ninja.id}>
            <div>Name: {ninja.name}</div>
            <div>Age: {ninja.age}</div>
            <div>Belt: {ninja.belt}</div>
            <button onClick = {() => {deleteNinja(ninja.id)}}>Delete</button>
        </div>
       ): null;
   });
    return(
        <div className="ninja-list">
            {ninjaList}
        </div>
    )
}

export default Ninjas;

/*    My Code 
import React from 'react';

const Ninja = (props) => {
    const {ninjas, deleteNinja} = props;

    const ninjaList = ninjas.map((ninja)=>{
        const {name, age, belt} = ninja;
        return (age>=25)?(
            <div key={ninja.id}>
                <h3>Name: {name}, Age; {age}, Belt: {belt}</h3>
                <button onClick={()=>{deleteNinja(ninja.id)}}>Delete Me</button>
            </div>
        ):null;
    });

    return(
       <div>
           {ninjaList}
       </div>
    )
}

export default Ninja;

*/