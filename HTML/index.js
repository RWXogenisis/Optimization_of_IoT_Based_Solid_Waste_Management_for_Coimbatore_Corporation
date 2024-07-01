const firebaseConfig = {
    apiKey: "AIzaSyCHZzw4th5UgasGNV7oTJN76iSyMCq47aQ",
    authDomain: "smart-19ba9.firebaseapp.com",
    projectId: "smart-19ba9",
    storageBucket: "smart-19ba9.appspot.com",
    messagingSenderId: "406820679179",
    appId: "1:406820679179:web:db7c66f9c3a5aaf3bba10e"
  };

  // Initialize Firebase
  const app = initializeApp(firebaseConfig);

  //variables
  const auth = firebase.auth()
  const database = firebase.database()

  function Login(){
    Name = document.getElementById("name").value
    pass = document.getElementById("pass").value

    .auth.signInWithEmailAndPassword()
    .then(function(){

    })

    .catch(function(){
        var error_code = error.code
        var error_message = error.message

        alert(error_message)
    })

  }

  function validate()