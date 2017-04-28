//
//  Shader.fsh
//  cardet
//
//  Created by David Massey on 7/24/10.
//  Copyright N/A 2010. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
