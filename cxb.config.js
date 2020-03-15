module.exports = (opts) => {
	let module_name = opts.module_name;
	let config = {
		module_name: 'cvip',
		remote_path: 'repertory/cxb/',
		package_name: `${module_name}.tar.gz?version=${opts.version}-${opts.platform}-${opts.arch}`,
		host: 'https://passoa-generic.pkg.coding.net',
		external: {
			opencv: 'https://github.com/losper/opencv/releases/download/v3.4.6/opencv-msvc-3.4.6.zip'
		},
		build_cmd: {
			windows_x86: [ `-DBT_APP=${module_name}` ],
			node_x64: [ '-G', 'Visual Studio 15 2017 Win64', '-DNODE=1' ]
		}
	};
	return config;
};