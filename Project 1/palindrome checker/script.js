document.getElementById("check-btn").onclick = function () {
  const input = document.getElementById("text-input").value;
  const output = document.getElementById("output");

  if (!input) {
    output.textContent = "⚠️ Please enter a number.";
    return;
  }

  const reversed = input.split('').reverse().join('');

  if (input === reversed) {
    output.textContent = `${input} is a palindrome ✅ `;
  } else {
    output.textContent = `${input} is not a palindrome ❌ `;
  }
};
