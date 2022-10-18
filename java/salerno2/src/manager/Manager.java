package manager;
import java.util.List;

public interface Manager<T> {

	void add(T element);
		
	void remove(T element);

    boolean containsElement(T element);
	
	List<T> getElements();
}

