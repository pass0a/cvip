var fs = require('fs-extra');
var path = require('path');
fs
	.copy('../output/node_modules/cvip/', path.resolve(__dirname, 'dist/'))
	.then(() => {
		console.log('copy core success!');
	})
	.catch((err) => {
		console.error(err);
	});