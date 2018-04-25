/* assemble required node modules */
var potrace = require('potrace');
var fs = require('fs');
var puppeteer = require('puppeteer');

/* parse command line arguments */
var args = process.argv.slice(2);

/* run potrace to trace input command line arg image to SVG */
potrace.trace('./' + args[0], function(err, svg) {
  if (err) throw err;
  fs.writeFileSync('./output.svg', svg);
});

/* function to provide a delay in puppeteer */
function delay(timeout) {
  return new Promise((resolve) => {
    setTimeout(resolve, timeout);
  });
}

(async () => {
  const browser = await puppeteer.launch({
	headless: false,
        executablePath: '/usr/bin/chromium-browser'
  });
  const page = await browser.newPage();
  await page.setViewport({ width: 3000, height: 1000 });
  await page._client.send('Page.setDownloadBehavior', {behavior: 'allow', downloadPath: './'});
  await page.goto('file:///home/jon/auto-a-sketch/toolpath/jscut/jscut.html');
  // await page.goto(__dirname + '/jscut/jscut.html');
  

  /*linkHandler = (await page.$x("//a[contains(text(), 'Open SVG')]"))[0];
  if (linkHandler)
    await linkHandler.click();
*/

  settings_uploader = (await page.$x("//input[@id='choose-settings-file']"))[0];
  if (settings_uploader)
    await settings_uploader.uploadFile('settings.jscut');

  svg_uploader = (await page.$x("//input[@id='choose-svg-file']"))[0];
  if (svg_uploader)
    await svg_uploader.uploadFile('output.svg');

  create_operation = (await page.$x("//button[@id='createOperationButton']"))[0];
  if (create_operation)
    await create_operation.click();

  await delay(500);
  //await page.screenshot({path: 'webpage1.png'});

  generate_operation = (await page.$x("//a[@id='opGenerate']"))[0];
  if (generate_operation)
    await generate_operation.click();

  await delay(500);

  await page.waitForFunction('document.getElementsByClassName("alert-info")[0].innerHTML.includes("Save your gcode");');
//await page.waitForFunction('document.getElementById("AlertNum6") != null');
  
  await delay(500);

  /*simulate_tab = (await page.$x("//a[@href='#simulatePanel']"))[0];
  if (simulate_tab)
    await simulate_tab.click();*/

   save_button = (await page.$x("//a[@href='#save-gcode-modal']"))[0];
   if (save_button)
	await save_button.click();

   await delay(1000);

   //await page.screenshot({path: 'webpage2.png'});

   save_gcode = (await page.$x("//button[@id='saveGcodeLocalFile']"))[0];
   if (save_gcode)
	await save_gcode.click();

   await delay(2000);


  await browser.close();
})();