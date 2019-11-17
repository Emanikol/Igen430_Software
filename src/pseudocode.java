

public class Pseudocode {


    /**
     * Move the platform so that it follows a specified path made from coordinates.
     * @param a list full of x and y coordinates, representing a path that the device needs to follow
     * @requires - the coordinates are within the reachable workspace
     * @return void -- move the device
     */
    public static void movePlatform(double x, double y) {

        moveMotorX(x);
        moveMotorY(y);


        return;
    }


    /**
     * Moves the motor to the specified coordinate
     * @param the result from calculateMotorX
     * @return void --> spins motor
     */
    public void moveMotorX(double xCoordinate) {
        //Insert code

        amountSteps = abs(calculateMotorX(xCoordinate));

        //Turn motorX forwards
        if (calculateMotorX(xCoordinate) > 0 ) {
            stepMotorForwards(amountSteps);
        }
        //Turn motorY backwards
        else if (calculateMotorX(xCoordinate) < 0 ) {
            stepMotorBackwards(amountSteps);
        }


        return;
    }


    /**
     * Moves the motor to the specified coordinate
     * @param the result from calculateMotorY
     * @return void --> spins motor
     */
    public void moveMotorY(double yCoordinate) {
        //Insert code

        amountSteps = abs(calculateMotorY(yCoordinate));

        //Turn motorX forwards
        if (calculateMotorY(yCoordinate) > 0 ) {
            stepMotorForwards(amountSteps);
        }
        //Turn motorY backwards
        else if (calculateMotorY(yCoordinate) < 0 ) {
            stepMotorBackwards(amountSteps);
        }
        return;
    }

    /**
     * Calculate the required amount Motor X has to spin in order to move, calculations will involve how the moving point
     *      * is related to the motor spinning through the flexural joints
     * @param he x coordinate and the length 1
     * @return value representing the amount of steps motor needs to take
     */
    public double calculateMotorX(double xCoordinate) {
        //Insert code
        requiredXMovement = calculateMovementX(xCoordinate);

        movementMotorX = requiredXMovement * Constant

        return movementMotorX;
    }


    /**
     * Calculate the required amount Motor Y has to spin in order to move, calculations will involve how the moving point
     * is related to the motor spinning through the flexural joints
     * @param the y coordinate and the length 2
     * @return value representing the amount of steps motor needs to take
     */
    public double calculateMotorY(double yCoordinate) {
        //Insert code
        requiredYMovement = calculateMovementY(yCoordinate);

        movementMotorY = requiredYMovement * Constant;

        return movementMotorY;
    }



    /**
     * Calculate the required movement on x axis and required direction
     * @param the x coordinate and the length 1
     * @return value representing x movement
     */
    public double calculateMovementX(double xCoordinate) {
        //Insert code
        movementX = xCoordinate - previousXCoordinate;
        return movementX;
    }

    /**
     * Calculate the required movement on y axis and required direction
     * @param the y coordinate and the length 2
     * @return value representing x movement,
     */
    public double calculateMovementY(double yCoordinate) {
        //Insert code
        movementY = yCoordinate - previousYCoordinate;
        return movementY;
    }

















}