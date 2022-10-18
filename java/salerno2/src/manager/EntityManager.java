package manager;
import java.util.ArrayList;
import java.util.List;

public class EntityManager<T> implements Manager<T> {
	
	private List<T> elements = new ArrayList<>();

	public EntityManager(){
	}

	public EntityManager(List<T> elements) {
		this.elements = elements;
	}
	
	@Override
	public void add(T element) {
		elements.add(element);
	}
	
	@Override
	public void remove(T element) {
		elements.remove(element);
	}
	
	@Override
	public boolean containsElement(T element) {
		return elements.contains(element);
	}

	@Override
    public List<T> getElements() {
        return this.elements;
    }
}

