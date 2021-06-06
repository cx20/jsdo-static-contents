function createSectorGeometry(innerRadius, outerRadius, startAngle, endAngle, segments, thickness) {
    var shape = new THREE.Shape();
    var i, x, y;
    if ( outerRadius > 0 ) {
        for(i = startAngle; i <= endAngle; i += (360/segments)) {
            x = outerRadius * Math.sin(2*Math.PI*i/360);
            y = outerRadius * Math.cos(2*Math.PI*i/360);
            if ( i === startAngle) {
                shape.moveTo(x, y);
            }
            shape.lineTo(x, y);
        }
    }
    if ( innerRadius > 0 ) {
        for(i = endAngle; i >= startAngle; i -= (360/segments)) {
            x = innerRadius * Math.sin(2*Math.PI*i/360);
            y = innerRadius * Math.cos(2*Math.PI*i/360);
            shape.lineTo(x, y);
        }
    }

    var parameters = {
        amount: thickness,
        bevelEnabled: false,
        bevelSegments: 2,
        bevelThickness: 5,
        bevelSize: 3
    };
    
    var geometry = new THREE.ExtrudeGeometry(shape, parameters);
    var material = new THREE.MeshPhongMaterial({
        color: 0x00AFFF,
        specular: 0x111111,
        shininess: 20
    });
    var extrude = new THREE.Mesh(geometry, material);
    extrude.position.z -= thickness/2;
    return extrude;
}

window.onload = function() {
    var controls;
    var scene = new THREE.Scene();
    var camera = new THREE.PerspectiveCamera( 75, window.innerWidth/window.innerHeight, 0.1, 1000 );
    camera.position.z = 150;

    var renderer = new THREE.WebGLRenderer();
    renderer.setSize( window.innerWidth, window.innerHeight );
    document.body.appendChild( renderer.domElement );

    controls = new THREE.OrbitControls( camera, renderer.domElement );
    controls.userPan = false;
    controls.userPanSpeed = 0.0;
    controls.maxDistance = 5000.0;
    controls.autoRotate = true;
    controls.autoRotateSpeed = 5.0;

    var light = new THREE.DirectionalLight(0xffffff);
    light.position.set(100, 100, 100);
    scene.add(light);
    
    var light2 = new THREE.AmbientLight(0xa0a0a0);
    scene.add(light2);

    var extrudeUpper  = createSectorGeometry(25, 50, -90, 90, 36, 5);
    var extrudeDown   = createSectorGeometry(25, 50, 90, 270, 36, 5);
    var extrudeCenter = createSectorGeometry(0, 23, 0, 360, 36, 5);
    var extrudeOuter1 = createSectorGeometry(62, 70, 0, 360, 36, 5);
    var extrudeOuter2 = createSectorGeometry(71, 75, 0, 360, 36, 2);
    extrudeCenter.name = 'extrudeCenter';
    extrudeOuter1.name = 'extrudeOuter1';
    extrudeOuter2.name = 'extrudeOuter2';

    extrudeUpper.position.y += 1;
    extrudeDown.position.y -= 1;
    scene.add(extrudeUpper);
    scene.add(extrudeDown);
    scene.add(extrudeCenter);
    scene.add(extrudeOuter1);
    scene.add(extrudeOuter2);

    // set up rotation about x axis
    const yAxis = new THREE.Vector3( 0, 1, 0 );
    
    const qInitial = new THREE.Quaternion().setFromAxisAngle( yAxis, 0 );
    const qCW_1of4 = new THREE.Quaternion().setFromAxisAngle( yAxis, Math.PI / 2 );
    const qCW_2of4 = new THREE.Quaternion().setFromAxisAngle( yAxis, Math.PI );
    const qCW_3of4 = new THREE.Quaternion().setFromAxisAngle( yAxis, Math.PI * 3 / 2);
    const qCW_4of4 = new THREE.Quaternion().setFromAxisAngle( yAxis, 0 );

    const qCCW_1of4 = new THREE.Quaternion().setFromAxisAngle( yAxis, -Math.PI / 2 );
    const qCCW_2of4 = new THREE.Quaternion().setFromAxisAngle( yAxis, -Math.PI );
    const qCCW_3of4 = new THREE.Quaternion().setFromAxisAngle( yAxis, -Math.PI * 3 / 2);
    const qCCW_4of4 = new THREE.Quaternion().setFromAxisAngle( yAxis, 0 );


    var rotationKeyframeTrackJSON1 = { name: 'extrudeCenter.quaternion', type: "quaternion", times: [ 
        0, 
        6 * 1/12,
        6 * 2/12,
        6 * 3/12,
        6 * 4/12,
        6 * 5/12,
        6 * 6/12,
        6 * 7/12,
        6 * 8/12,
        6 * 9/12,
        6 * 10/12,
        6 * 11/12,
        6 * 12/12
    ], values: [
        qInitial.x, qInitial.y, qInitial.z, qInitial.w, 
        qCW_1of4.x, qCW_1of4.y,qCW_1of4.z, qCW_1of4.w, 
        qCW_2of4.x, qCW_2of4.y,qCW_2of4.z, qCW_2of4.w, 
        qCW_3of4.x, qCW_3of4.y,qCW_3of4.z, qCW_3of4.w, 
        qCW_4of4.x, qCW_4of4.y,qCW_4of4.z, qCW_4of4.w,
        qCW_1of4.x, qCW_1of4.y,qCW_1of4.z, qCW_1of4.w, 
        qCW_2of4.x, qCW_2of4.y,qCW_2of4.z, qCW_2of4.w, 
        qCW_3of4.x, qCW_3of4.y,qCW_3of4.z, qCW_3of4.w, 
        qCW_4of4.x, qCW_4of4.y,qCW_4of4.z, qCW_4of4.w,
        qCW_1of4.x, qCW_1of4.y,qCW_1of4.z, qCW_1of4.w, 
        qCW_2of4.x, qCW_2of4.y,qCW_2of4.z, qCW_2of4.w, 
        qCW_3of4.x, qCW_3of4.y,qCW_3of4.z, qCW_3of4.w, 
        qCW_4of4.x, qCW_4of4.y,qCW_4of4.z, qCW_4of4.w 
    ]}
    var rotationKeyframeTrackJSON2 = { name: 'extrudeOuter1.quaternion', type: "quaternion", times: [ 
        0, 
        6 * 1/8, 
        6 * 2/8, 
        6 * 3/8, 
        6 * 4/8, 
        6 * 5/8, 
        6 * 6/8, 
        6 * 7/8, 
        6 * 8/8 
    ], values: [ 
        qInitial.x, qInitial.y, qInitial.z, qInitial.w, 
        qCCW_1of4.x, qCCW_1of4.y,qCCW_1of4.z, qCCW_1of4.w, 
        qCCW_2of4.x, qCCW_2of4.y,qCCW_2of4.z, qCCW_2of4.w, 
        qCCW_3of4.x, qCCW_3of4.y,qCCW_3of4.z, qCCW_3of4.w, 
        qCCW_4of4.x, qCCW_4of4.y,qCCW_4of4.z, qCCW_4of4.w,
        qCCW_1of4.x, qCCW_1of4.y,qCCW_1of4.z, qCCW_1of4.w, 
        qCCW_2of4.x, qCCW_2of4.y,qCCW_2of4.z, qCCW_2of4.w, 
        qCCW_3of4.x, qCCW_3of4.y,qCCW_3of4.z, qCCW_3of4.w, 
        qCCW_4of4.x, qCCW_4of4.y,qCCW_4of4.z, qCCW_4of4.w
    ]}
    var rotationKeyframeTrackJSON3 = { name: 'extrudeOuter2.quaternion', type: "quaternion", times: [ 
        0, 
        6 * 1/4, 
        6 * 2/4, 
        6 * 3/4, 
        6 * 4/4 
    ], values: [ 
        qInitial.x, qInitial.y, qInitial.z, qInitial.w, 
        qCW_1of4.x, qCW_1of4.y,qCW_1of4.z, qCW_1of4.w, 
        qCW_2of4.x, qCW_2of4.y,qCW_2of4.z, qCW_2of4.w, 
        qCW_3of4.x, qCW_3of4.y,qCW_3of4.z, qCW_3of4.w, 
        qCW_4of4.x, qCW_4of4.y,qCW_4of4.z, qCW_4of4.w 
    ]}

    var clipJSON = { duration: 6, tracks: [ 
        rotationKeyframeTrackJSON1, 
        rotationKeyframeTrackJSON2, 
        rotationKeyframeTrackJSON3 
    ] }


    var clip = THREE.AnimationClip.parse(clipJSON);
    var mixer = new THREE.AnimationMixer(extrudeOuter2)
    var action = mixer.clipAction(clip)
    action.play()

    function exportGLTF(input) {
        var gltfExporter = new THREE.GLTFExporter();
        var options = {
            binary: true,
            animations: [clip]
        };
        gltfExporter.parse( input, function( result ) {
            if ( result instanceof ArrayBuffer ) {
                saveArrayBuffer( result, 'scene.glb' );
            } else {
                var output = JSON.stringify( result, null, 2 );
                console.log( output );
                saveString( output, 'scene.gltf' );
            }
        }, options );
    }

    document.getElementById('export_scene').addEventListener('click', function() {

        exportGLTF(scene);

    });

    var link = document.createElement('a');
    link.style.display = 'none';
    document.body.appendChild(link); // Firefox workaround, see #6594

    function save( blob, filename ) {
        link.href = URL.createObjectURL( blob );
        link.download = filename;
        link.click();
        // URL.revokeObjectURL( url ); breaks Firefox...
    }

    function saveString( text, filename ) {
        save( new Blob( [ text ], { type: 'text/plain' } ), filename );
    }

    function saveArrayBuffer( buffer, filename ) {
        save( new Blob( [ buffer ], { type: 'application/octet-stream' } ), filename );
    }


    var render = function () {
        requestAnimationFrame( render );

        mixer.update(0.01)

        renderer.render(scene, camera);
        controls.update();
    };

    render();
  
};
