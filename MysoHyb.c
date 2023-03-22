#include <ApplicationServices/ApplicationServices.h>
#include <unistd.h>

int main ( int argc, char *argv[] ) {
	
	CGEventRef move1 = CGEventCreateMouseEvent(
        	NULL, kCGEventMouseMoved,
        	CGPointMake(200, 200),
        	kCGMouseButtonLeft
	);

	CGEventRef move2 = CGEventCreateMouseEvent(
        	NULL, kCGEventMouseMoved,
        	CGPointMake(100, 100),
        	kCGMouseButtonLeft
	);
	

	int duration = atoi(argv[1]);
	duration = duration / 10;

	for ( int i = 0; i < duration; i++ ) {
		CGEventPost(kCGHIDEventTap, move1);
		sleep(10);

		CGEventPost(kCGHIDEventTap, move2);
		sleep(10);
	}
    
	
	CFRelease(move2);
	CFRelease(move1);
	return 0;
}
