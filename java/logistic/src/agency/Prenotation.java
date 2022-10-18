package agency;

import exceptions.InsufficientFleetCapacityException;
import exceptions.InvalidLoadCompositionException;
import exceptions.InvalidPrenotationException;
import goods.LoadInfo;
import logistics.Delivery;

public class Prenotation {

    private Delivery delivery;

    public Prenotation(Delivery delivery) throws InvalidPrenotationException, InsufficientFleetCapacityException {

        this.delivery = delivery;

        try {
            this.validate();
        } catch (InvalidLoadCompositionException e) {
            throw new InvalidPrenotationException("Failed to validate LoadInfo");
        }
    }

    private void validate() throws InvalidLoadCompositionException, InvalidPrenotationException, InsufficientFleetCapacityException {

        //validate loadInfo
        LoadInfo temp = this.delivery.getLoadInfo();

        temp.validate();


        //validate fleet

        Float temp = this.delivery.getLoadInfo().getLoadWeight();
        
        if(temp > this.delivery.getFleet().calculateCapacity()) {

            throw new InsufficientFleetCapacityException();

        }

    }
    
}

