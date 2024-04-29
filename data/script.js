const temperatureValue = document.getElementById("temperature");
const humidityValue = document.getElementById("humidity");
const pressureValue = document.getElementById("pressure");

const temperatureIcon = document.getElementById("temperature-icon");
const humidityIcon = document.getElementById("humidity-icon");

const humidityIconNames = ["humidity_low", "humidity_mid", "humidity_high"];
const temperatureIconNames = ["ac_unit", "thermometer", "mode_heat"];

const updateValues = function () {
  location.reload();

  // temperatureValue = newDoc.getElementById("temperature");
  // humidityValue = newDoc.getElementById("humidity");

  const tempV = temperatureValue.textContent;

  if (tempV <= 0) temperatureIcon.textContent = temperatureIconNames[0];
  else if (tempV > 0 && tempV < 30)
    temperatureIcon.textContent = temperatureIconNames[1];
  else if (tempV >= 30) temperatureIcon.textContent = temperatureIconNames[2];

  let humV = humidityValue.textContent;
  if (humV > 0 && humV < 40) humidityIcon.textContent = humidityIconNames[0];
  else if (humV >= 40 && humV < 70)
    humidityIcon.textContent = humidityIconNames[1];
  else if (humV > 70) humidityIcon.textContent = humidityIconNames[2];
};


setInterval(updateValues, 5000);

const test = async function(){
  const newDoc = await fetch("http://192.168.121.223/").then(response=>response.text());
  console.log(newDoc);
  const tempCont ='id="temperature">';
  const text = newDoc.search(tempCont);
  console.log(text);
  const data = newDoc.substring(text+tempCont.length);
  // w tym data dodać search od id do pierwszego <
  console.log(newDoc[text+tempCont.length]);
}

setInterval(test, 1000);