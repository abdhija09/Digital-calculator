let input = document.getElementById('inputbox');
let buttons = document.querySelectorAll('button');

let string = "";
let arr = Array.from(buttons);

arr.forEach(button => {
    button.addEventListener('click', (e) => {
        if (e.target.innerHTML == '=') {
            string=eval(string);
            input.value=string;
            
        } else if (e.target.innerHTML == 'AC') {
            string = "";
            input.value = string;
        } else if (e.target.innerHTML == "DEL") {
            string = string.substring(0, string.length - 1);
            input.value = string;
           
        } 
        else if (e.target.innerHTML == "!") {
            function factorial(n) {
                let f = 1;
                for (let i = 1; i <= n; i++) {
                    f *= i;
                }
                return f;
            }
        
            let num = parseInt(string); // Convert string to a number
            if (num >= 0) {
                string = factorial(num);
                input.value = string;
            } else {
                input.value = "Error"; // Handle negative numbers
                string = "";
            }

        }
        
          else {
            string += e.target.innerHTML;
            input.value = string;  // Fixed from "valve" to "value"
        }
    });
});
