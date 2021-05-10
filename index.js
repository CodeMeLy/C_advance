const fs = require('fs');
const download = require('download');

(async () => {
	await download('https://vietjack.com/html/images/logo3.png', 'dist');

	fs.writeFileSync('dist/foo.jpg', await download('https://vietjack.com/html/images/logo3.png'));

	download('unicorn.com/foo.jpg').pipe(fs.createWriteStream('dist/foo.jpg'));

	await Promise.all([
		'unicorn.com/foo.jpg',
		'cats.com/dancing.gif'
	].map(url => download(url, 'dist')));
    console.log("success");
})();