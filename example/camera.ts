import { Camera } from '../src/index';
import { join } from 'path';
async function main() {
	let cap = new Camera(1);
	let cap1 = new Camera(0);
	//console.log(cap.take());
	let idx = 0;
	cap.on('data', (data) => {
		//console.log('!!!:', data);
		if (idx == 0) {
			cap.startRecord(join(__dirname, 'test.avi'));
		}
		if (idx == 100) {
			cap.stopRecord();
		}
		idx++;
	});
	cap1.on('data', (data) => {
		//console.log(data);
	});
	setTimeout(() => {
		console.log('destroy1!!');
		cap.take(join(__dirname, 'test.jpg'));
		cap.destroy();
		cap1.destroy();
	}, 10000);
}
main();
