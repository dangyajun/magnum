#ifndef Magnum_SceneTools_Hierarchy_h
#define Magnum_SceneTools_Hierarchy_h
/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019,
                2020, 2021, 2022 Vladimír Vondruš <mosra@centrum.cz>

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

/** @file
 * @brief Function @ref Magnum::SceneTools::absoluteFieldTransformations2D(), @ref Magnum::SceneTools::absoluteFieldTransformations2DInto(), @ref Magnum::SceneTools::absoluteFieldTransformations3D(), @ref Magnum::SceneTools::absoluteFieldTransformations3DInto()
 * @m_since_latest
 */

#include "Magnum/Magnum.h"
#include "Magnum/SceneTools/visibility.h"
#include "Magnum/Trade/Trade.h"

namespace Magnum { namespace SceneTools {

/**
@brief Calculate absolute 2D transformations for given field
@m_since_latest

For all entries of given field in @p scene returns an absolute transformation
of the object they're attached to in the scene with @p globalTransformation
prepended. The @ref Trade::SceneField::Parent field is expected to be contained
in the scene, having no cycles or duplicates, the scene is expected to be 2D
and @p fieldId is expected to be less than @ref Trade::SceneData::fieldCount().
If the field is empty, the function returns an empty array.

The operation is done in an @f$ \mathcal{O}(m + n) @f$ execution time and
memory complexity, with @f$ m @f$ being size of @p fieldId and @f$ n @f$ being
@ref Trade::SceneData::mappingBound(). The function calls
@ref orderClusterParents() internally.

The returned data are in the same order as object mapping entries in
@p fieldId. Fields attached to objects without a @ref Trade::SceneField::Parent
or to objects in loose hierarchy subtrees will have their transformation set to
an unspecified value.

This function can be used for example to flatten a mesh hierarchy, bake
the transformations to actual meshes and then concatenate them together into a
single mesh:

@snippet MagnumSceneTools.cpp absoluteFieldTransformations2D-mesh-concatenate

@experimental

@see @ref absoluteFieldTransformations2D(const Trade::SceneData&, UnsignedInt, const Matrix3&),
    @ref absoluteFieldTransformations2DInto(),
    @ref absoluteFieldTransformations3D(), @ref Trade::SceneData::hasField(),
    @ref Trade::SceneData::is2D()
*/
#ifdef DOXYGEN_GENERATING_OUTPUT
MAGNUM_SCENETOOLS_EXPORT Containers::Array<Matrix3> absoluteFieldTransformations2D(const Trade::SceneData& scene, UnsignedInt fieldId, const Matrix3& globalTransformation = {});
#else
/* To avoid including Matrix3 */
MAGNUM_SCENETOOLS_EXPORT Containers::Array<Matrix3> absoluteFieldTransformations2D(const Trade::SceneData& scene, UnsignedInt fieldId, const Matrix3& globalTransformation);
MAGNUM_SCENETOOLS_EXPORT Containers::Array<Matrix3> absoluteFieldTransformations2D(const Trade::SceneData& scene, UnsignedInt fieldId);
#endif

/**
@brief Calculate absolute 2D transformations for given named field
@m_since_latest

Translates @p field to a field ID using @ref Trade::SceneData::fieldId() and
delegates to @ref absoluteFieldTransformations2D(const Trade::SceneData&, UnsignedInt, const Matrix3&).
The @p field is expected to exist in @p scene.
@experimental
*/
#ifdef DOXYGEN_GENERATING_OUTPUT
MAGNUM_SCENETOOLS_EXPORT Containers::Array<Matrix3> absoluteFieldTransformations2D(const Trade::SceneData& scene, Trade::SceneField field, const Matrix3& globalTransformation = {});
#else
/* To avoid including Matrix3 */
MAGNUM_SCENETOOLS_EXPORT Containers::Array<Matrix3> absoluteFieldTransformations2D(const Trade::SceneData& scene, Trade::SceneField field, const Matrix3& globalTransformation);
MAGNUM_SCENETOOLS_EXPORT Containers::Array<Matrix3> absoluteFieldTransformations2D(const Trade::SceneData& scene, Trade::SceneField field);
#endif

/**
@brief Calculate absolute 2D transformations for given field into an existing array
@param[in]  scene           Input scene
@param[in]  fieldId         Field to calculate the transformations for
@param[out] transformations Where to put the calculated transformations
@param[in]  globalTransformation Global transformation to prepend
@m_since_latest

A variant of @ref absoluteFieldTransformations2D(const Trade::SceneData&, UnsignedInt, const Matrix3&)
that fills existing memory instead of allocating a new array. The
@p transformations array is expected to have the same size as the @p fieldId.
@see @ref Trade::SceneData::fieldSize()
@experimental
*/
#ifdef DOXYGEN_GENERATING_OUTPUT
MAGNUM_SCENETOOLS_EXPORT void absoluteFieldTransformations2DInto(const Trade::SceneData& scene, UnsignedInt fieldId, const Containers::StridedArrayView1D<Matrix3>& transformations, const Matrix3& globalTransformation = {});
#else
/* To avoid including Matrix3 */
MAGNUM_SCENETOOLS_EXPORT void absoluteFieldTransformations2DInto(const Trade::SceneData& scene, UnsignedInt fieldId, const Containers::StridedArrayView1D<Matrix3>& transformations, const Matrix3& globalTransformation);
MAGNUM_SCENETOOLS_EXPORT void absoluteFieldTransformations2DInto(const Trade::SceneData& scene, UnsignedInt fieldId, const Containers::StridedArrayView1D<Matrix3>& transformations);
#endif

/**
@brief Calculate absolute 2D transformations for given named field into an existing array
@m_since_latest

Translates @p field to a field ID using @ref Trade::SceneData::fieldId() and
delegates to @ref absoluteFieldTransformations2DInto(const Trade::SceneData&, UnsignedInt, const Containers::StridedArrayView1D<Matrix3>&, const Matrix3&)
The @p field is expected to exist in @p scene.
@experimental
*/
#ifdef DOXYGEN_GENERATING_OUTPUT
MAGNUM_SCENETOOLS_EXPORT void absoluteFieldTransformations2DInto(const Trade::SceneData& scene, Trade::SceneField field, const Containers::StridedArrayView1D<Matrix3>& transformations, const Matrix3& globalTransformation = {});
#else
/* To avoid including Matrix3 */
MAGNUM_SCENETOOLS_EXPORT void absoluteFieldTransformations2DInto(const Trade::SceneData& scene, Trade::SceneField field, const Containers::StridedArrayView1D<Matrix3>& transformations, const Matrix3& globalTransformation);
MAGNUM_SCENETOOLS_EXPORT void absoluteFieldTransformations2DInto(const Trade::SceneData& scene, Trade::SceneField field, const Containers::StridedArrayView1D<Matrix3>& transformations);
#endif

/**
@brief Calculate absolute 2D transformations for given field
@m_since_latest

For all entries of given field in @p scene returns an absolute transformation
of the object they're attached to in the scene with @p globalTransformation
prepended. The @ref Trade::SceneField::Parent field is expected to be contained
in the scene, having no cycles or duplicates, the scene is expected to be 3D
and @p fieldId is expected to be less than @ref Trade::SceneData::fieldCount().
If the field is empty, the function returns an empty array.

The operation is done in an @f$ \mathcal{O}(m + n) @f$ execution time and
memory complexity, with @f$ m @f$ being size of @p fieldId and @f$ n @f$ being
@ref Trade::SceneData::mappingBound(). The function calls
@ref orderClusterParents() internally.

The returned data are in the same order as object mapping entries in
@p fieldId. Fields attached to objects without a @ref Trade::SceneField::Parent
or to objects in loose hierarchy subtrees will have their transformation set to
an unspecified value.

This function can be used for example to flatten a mesh hierarchy, bake
the transformations to actual meshes and then concatenate them together into a
single mesh:

@snippet MagnumSceneTools.cpp absoluteFieldTransformations3D-mesh-concatenate

@experimental

@see @ref absoluteFieldTransformations3D(const Trade::SceneData&, UnsignedInt, const Matrix4&),
    @ref absoluteFieldTransformations3DInto(),
    @ref absoluteFieldTransformations2D(), @ref Trade::SceneData::hasField(),
    @ref Trade::SceneData::is3D()
*/
#ifdef DOXYGEN_GENERATING_OUTPUT
MAGNUM_SCENETOOLS_EXPORT Containers::Array<Matrix4> absoluteFieldTransformations3D(const Trade::SceneData& scene, UnsignedInt fieldId, const Matrix4& globalTransformation = {});
#else
/* To avoid including Matrix4 */
MAGNUM_SCENETOOLS_EXPORT Containers::Array<Matrix4> absoluteFieldTransformations3D(const Trade::SceneData& scene, UnsignedInt fieldId, const Matrix4& globalTransformation);
MAGNUM_SCENETOOLS_EXPORT Containers::Array<Matrix4> absoluteFieldTransformations3D(const Trade::SceneData& scene, UnsignedInt fieldId);
#endif

/**
@brief Calculate absolute 3D transformations for given named field
@m_since_latest

Translates @p field to a field ID using @ref Trade::SceneData::fieldId() and
delegates to @ref absoluteFieldTransformations3D(const Trade::SceneData&, UnsignedInt, const Matrix4&).
The @p field is expected to exist in @p scene.
@experimental
*/
#ifdef DOXYGEN_GENERATING_OUTPUT
MAGNUM_SCENETOOLS_EXPORT Containers::Array<Matrix4> absoluteFieldTransformations3D(const Trade::SceneData& scene, Trade::SceneField field, const Matrix4& globalTransformation = {});
#else
/* To avoid including Matrix4 */
MAGNUM_SCENETOOLS_EXPORT Containers::Array<Matrix4> absoluteFieldTransformations3D(const Trade::SceneData& scene, Trade::SceneField field, const Matrix4& globalTransformation);
MAGNUM_SCENETOOLS_EXPORT Containers::Array<Matrix4> absoluteFieldTransformations3D(const Trade::SceneData& scene, Trade::SceneField field);
#endif

/**
@brief Calculate absolute 3D transformations for given field into an existing array
@param[in]  scene           Input scene
@param[in]  fieldId         Field to calculate the transformations for
@param[out] transformations Where to put the calculated transformations
@param[in]  globalTransformation Global transformation to prepend
@m_since_latest

A variant of @ref absoluteFieldTransformations3D(const Trade::SceneData&, UnsignedInt, const Matrix4&)
that fills existing memory instead of allocating a new array. The
@p transformations array is expected to have the same size as the @p fieldId.
@see @ref Trade::SceneData::fieldSize()
@experimental
*/
#ifdef DOXYGEN_GENERATING_OUTPUT
MAGNUM_SCENETOOLS_EXPORT void absoluteFieldTransformations3DInto(const Trade::SceneData& scene, UnsignedInt fieldId, const Containers::StridedArrayView1D<Matrix4>& transformations, const Matrix4& globalTransformation = {});
#else
/* To avoid including Matrix4 */
MAGNUM_SCENETOOLS_EXPORT void absoluteFieldTransformations3DInto(const Trade::SceneData& scene, UnsignedInt fieldId, const Containers::StridedArrayView1D<Matrix4>& transformations, const Matrix4& globalTransformation);
MAGNUM_SCENETOOLS_EXPORT void absoluteFieldTransformations3DInto(const Trade::SceneData& scene, UnsignedInt fieldId, const Containers::StridedArrayView1D<Matrix4>& transformations);
#endif

/**
@brief Calculate absolute 3D transformations for given named field into an existing array
@m_since_latest

Translates @p field to a field ID using @ref Trade::SceneData::fieldId() and
delegates to @ref absoluteFieldTransformations3DInto(const Trade::SceneData&, UnsignedInt, const Containers::StridedArrayView1D<Matrix4>&, const Matrix4&)
The @p field is expected to exist in @p scene.
@experimental
*/
#ifdef DOXYGEN_GENERATING_OUTPUT
MAGNUM_SCENETOOLS_EXPORT void absoluteFieldTransformations3DInto(const Trade::SceneData& scene, Trade::SceneField field, const Containers::StridedArrayView1D<Matrix4>& transformations, const Matrix4& globalTransformation = {});
#else
/* To avoid including Matrix4 */
MAGNUM_SCENETOOLS_EXPORT void absoluteFieldTransformations3DInto(const Trade::SceneData& scene, Trade::SceneField field, const Containers::StridedArrayView1D<Matrix4>& transformations, const Matrix4& globalTransformation);
MAGNUM_SCENETOOLS_EXPORT void absoluteFieldTransformations3DInto(const Trade::SceneData& scene, Trade::SceneField field, const Containers::StridedArrayView1D<Matrix4>& transformations);
#endif

}}

#endif
