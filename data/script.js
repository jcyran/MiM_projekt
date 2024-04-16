const temperatureValue = document.getElementById("temperature");
const humidityValue = document.getElementById("humidity");
const pressureValue = document.getElementById("pressure");

const temperatureIcon = document.getElementById("temperature-icon");
const humidityIcon = document.getElementById("humidity-icon");

const humidityIconNames = ["humidity_low", "humidity_mid", "humidity_high"];
const temperatureIconNames = ["ac_unit", "thermometer", "mode_heat"];

const updateValues = function () {
  const tempV = temperatureValue.textContent;
  console.log(tempV);
  console.log(temperatureIcon);
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

setInterval(updateValues, 1000);