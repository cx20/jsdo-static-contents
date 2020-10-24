import { Mesh, NodeIO, Primitive, Root } from '@gltf-transform/core';

const io = new NodeIO();
const doc = io.read('./VC.glb');
const root = doc.getRoot();

root.listMaterials()
	.filter((mat) => !mat.getBaseColorTexture())
	.forEach((mat) => {

		for (const prim of mat.listParents() as Primitive[]) {
			if (prim instanceof Root) continue;

			prim.listParents()
				.filter((mesh: Mesh) => mesh.listPrimitives().length === 1)
				.forEach((mesh) => mesh.dispose());
			prim.dispose();
		}

		mat.dispose();
	});

root.listAccessors()
	.filter((accessor) => accessor.listParents().length === 1)
	.forEach((accessor) => accessor.dispose());

io.write('./VC-fixed.glb', doc);