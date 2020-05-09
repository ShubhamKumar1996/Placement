user = {
    name: "shubham",
    age: 24,
    email: "badkadad@gmail.com",
    username: "1996Shaitaan",
    blogs: ["This is Working", "That is not working"],
    login: function(){
        console.log("The user logged in");
    },
    logout: ()=>{ console.log("The user logged out")},
    logBlogs: function(){
        this.blogs.forEach(blog => {
            console.log(blog);
        });
    }
};

user.login();
user.logout();
user.logBlogs();