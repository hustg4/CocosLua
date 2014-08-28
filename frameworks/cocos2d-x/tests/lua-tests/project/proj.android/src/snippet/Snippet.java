package snippet;

public class Snippet {
	  public Cocos2dxGLSurfaceView onCreateView() {
	        Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
	        // Tests should create stencil buffer
	        glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
	        
	        return glSurfaceView;
	    }
}

