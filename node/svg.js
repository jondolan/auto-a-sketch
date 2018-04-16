var potrace = require('potrace'),
    fs = require('fs');

potrace.trace('./input.jpg', function(err, svg) {
  if (err) throw err;
  fs.writeFileSync('./output.svg', svg);
});
