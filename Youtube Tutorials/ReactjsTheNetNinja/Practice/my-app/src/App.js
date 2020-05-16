
import React, {Component} from 'react';
import Ninjas from "./Ninjas";
import AddNinja from "./AddNinja";

class App extends Component{
  state = {
    ninjas: [
      {name: "Ryu", age: 23, belt:"black", id:1},
      {name: "Yoshi", age:25, belt:"green", id:2},
      {name: "Crystal", age:26, belt:"pink", id:3}
    ]
  }
  addNinja = (ninja) => {
    ninja.id = Math.random();
    let ninjas = [...this.state.ninjas, ninja];
    this.setState({
        ninjas: ninjas
    });
  }

  deleteNinja = (id) => {
    let NewNinjas = this.state.ninjas.filter((ninja)=>{
      return ninja.id!==id;
    });
    this.setState({
      ninjas: NewNinjas
    });
  }

  render(){
    return (
      <div className="App">
        <h1>My first React App!</h1>
        <Ninjas ninjas={this.state.ninjas} deleteNinja = {this.deleteNinja}/>
        <AddNinja addNinja = {this.addNinja}/>
      </div>
    );
  }
}

export default App;


/* My Code
import React, {Component} from 'react';
import Ninjas from "./Ninjas";
import AddNinja from "./AddNinja";

class App extends Component{
  state = {
    ninjas: [
      {id:1, name: "Ryu", age: 30, belt: "black"},
      {id:2, name: "Yoshi", age: 25, belt: "Green"},
      {id:3, name: "Nobita", age: 20, belt: "orange"},
    ]
  }
  addNinja = (ninja) => {
    let updatedNinjas = [...this.state.ninjas, ninja];
    this.setState({
      ninjas: updatedNinjas
    });
  }
  deleteNinja = (id)=>{
    const updatedNinjas = this.state.ninjas.filter((ninja)=>{
      return ninja.id!==id;
    })
    console.log(updatedNinjas);
    this.setState({
      ninjas: updatedNinjas
    });
  }
  render(){
    return(
      <div className="App">
        <Ninjas ninjas = {this.state.ninjas} deleteNinja={this.deleteNinja}/>
        <AddNinja addNinja = {this.addNinja}/>
      </div>
    )
  }
}

export default App;

*/