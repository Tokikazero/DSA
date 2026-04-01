let currentValues = [];
let numberOfDoors = 7;
const doorsContainer = document.querySelector(".doors");
const message = document.getElementById("message");
const resetGame = document.getElementById("resetGame");
const sortButton = document.getElementById("sortButton");
const increaseDoors = document.getElementById("increaseDoors");
const moveFifty = document.getElementById("moveFifty");

function initializeGame() {
  currentValues = generateRandomValues(numberOfDoors);
  doorsContainer.innerHTML = "";
  for (let i = 0; i < numberOfDoors; i++) {
    const door = document.createElement("div");
    door.classList.add("door");
    door.textContent = "Door " + i;
    door.addEventListener("click", () => checkGuess(i));
    doorsContainer.appendChild(door);
  }
  message.textContent = "Click on a door to find the $50 bill!";
  resetGame.style.display = "none";
}

function generateRandomValues(numDoors) {
  if (numDoors === 7) {
    return [1, 5, 10, 20, 50, 100, 500];
  }

  const uniqueValues = new Set();

  uniqueValues.add(50);

  while (uniqueValues.size < numDoors) {
    const randomValue = Math.floor(Math.random() * 100) * 5;
    if (randomValue > 0 && randomValue <= 500) {
      uniqueValues.add(randomValue);
    }
  }

  return Array.from(uniqueValues);
}

function checkGuess(doorNumber) {
  const value = currentValues[doorNumber];
  document.querySelectorAll(".door")[doorNumber].textContent = value;

  if (value === 50) {
    message.textContent =
      "Congratulations! You found the $50 bill behind Door " + doorNumber + "!";
    revealDoors();
  } else {
    message.textContent =
      "Nope, there is no $50 bill behind Door " + doorNumber + ". Try again!";
    document.querySelectorAll(".door")[doorNumber].style.backgroundColor =
      "red";
  }
}

function revealDoors() {
  const doors = document.querySelectorAll(".door");
  doors.forEach((door, index) => {
    door.textContent = currentValues[index];
    door.style.pointerEvents = "none";
  });
  resetGame.style.display = "block";

  const found = binarySearch(currentValues, 50, 0, currentValues.length - 1);
  if (found) {
    message.textContent +=
      " The binary search confirmed the $50 is behind one of the doors!";
  } else {
    message.textContent += " The binary search did not find the $50 bill.";
  }
}

function binarySearch(arr, target, left, right) {
  if (left > right) {
    return false;
  }

  const middle = Math.floor((left + right) / 2);

  if (arr[middle] === target) {
    return true;
  } else if (target < arr[middle]) {
    return binarySearch(arr, target, left, middle - 1);
  } else {
    return binarySearch(arr, target, middle + 1, right);
  }
}

function shuffleArray(array) {
  for (let i = array.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    [array[i], array[j]] = [array[j], array[i]];
  }
  return array;
}

function sortValues() {
  currentValues.sort((a, b) => a - b);
  message.textContent = "The values have been sorted internally.";
}

function moveFiftyToLastDoor() {
  const fiftyIndex = currentValues.indexOf(50);
  if (fiftyIndex !== -1) {
    const fiftyValue = currentValues[fiftyIndex];
    currentValues.splice(fiftyIndex, 1);
    currentValues.push(fiftyValue);
  }

  hideDoorValues();
  message.textContent = "$50 has been moved to a new position! Keep guessing!";
}

function hideDoorValues() {
  const doors = document.querySelectorAll(".door");
  doors.forEach((door, index) => {
    door.textContent = "Door " + index;
    door.style.backgroundColor = "blue";
    door.style.pointerEvents = "auto";
  });
}

function updateDoorDisplay() {
  const doors = document.querySelectorAll(".door");
  doors.forEach((door, index) => {
    door.textContent = currentValues[index];
  });
}

function increaseNumberOfDoors() {
  if (numberOfDoors < 100) {
    numberOfDoors++;
    initializeGame();
  } else {
    message.textContent = "You have reached the maximum number of doors (100).";
  }
}

resetGame.addEventListener("click", () => {
  initializeGame();
});
sortButton.addEventListener("click", sortValues);
increaseDoors.addEventListener("click", increaseNumberOfDoors);
moveFifty.addEventListener("click", moveFiftyToLastDoor);

initializeGame();
