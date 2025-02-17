#ifndef PARAMWORLD_TreeObject_h
#define PARAMWORLD_TreeObject_h
#include "OculusWorldDemo.h"
#include "Kernel/OVR_Color.h"
#include "SceneObjects/AvailableParameters.h"
#include <vector>
#include "SceneObject.h"

namespace ParamWorld {
	class TreeObject : public SceneObject {
	public:
		Ptr<Model> ModelX;

		TreeObject(Vector3f root, int depth, float height, float width, float scale, float angle, OVR::Color leafColor, OVR::Color trunkColor, float leafSize);

		TreeObject(Vector3f root, float *params) :
			SceneObject(params, root),
			_depth((int)params[SP_Depth]), _height(params[SP_Height]), _width(params[SP_Width]),
			_scale(params[SP_Scale]), _splitAngle(params[SP_SplitAngle]),
			_leafColor((char)params[SP_LeafR], (char)params[SP_LeafG], (char)params[SP_LeafB], 0),
			_trunkColor((char)params[SP_BranchR], (char)params[SP_BranchG], (char)params[SP_BranchB], 0),
			_leafSize(params[SP_LeafSize])
		{
			for (int i = 0; i < SP_Count; i++) {
				WriteLog("param[%d]: %f", i, params[i]);
			}
			WriteLog("Depth: %d, Height: %f, ");
			ModelX = new Model();
			initModels(root, Vector3f(_width, _height, _width), _depth, Quatf(0, 0, 0, 1));
		}

	private:
		int _depth;
		float _height, _width, _scale, _splitAngle, _leafSize;
		OVR::Color _leafColor, _trunkColor;

		void initModels(Vector3f root, Vector3f dims, int depth, Quatf angleFromY);
	};
}

#endif
